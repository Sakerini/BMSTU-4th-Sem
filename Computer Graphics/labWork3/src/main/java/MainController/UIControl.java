package MainController;

import Drawer.Line;
import Timer.TimeHistory;
import Timer.Timer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.image.PixelWriter;

import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class UIControl implements Initializable {

    @FXML
    public MenuItem help;

    @FXML
    public TextField textFieldX1;
    @FXML
    public TextField textFieldX2;
    @FXML
    public TextField textFieldY1;
    @FXML
    public TextField textFieldY2;

    @FXML
    public TextField textFieldXc;
    @FXML
    public TextField textFieldYc;
    @FXML
    public TextField textFieldL;
    @FXML
    public TextField textFieldDegrees;

    @FXML
    public ColorPicker colorPicker;

    @FXML
    public Canvas canvas;
    private GraphicsContext gc;
    private PixelWriter pw;

    @FXML
    public ComboBox<String> algorithmComboBox;

    private double canvasHeight;
    private double canvasWidth;

    private TimeHistory timeHistory = new TimeHistory(new ArrayList<Timer>());

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        ObservableList<String> list = FXCollections.observableArrayList(
                "DDA",
                "Bresenham's line algorithm (Float)",
                "Bresenham's line algorithm (Integer)",
                "Bresenham's line algorithm (Step Removal)",
                "By",
                "Library algorithm"
        );
        algorithmComboBox.setItems(list);

        canvasHeight = canvas.getHeight();
        canvasWidth = canvas.getWidth();
        gc = canvas.getGraphicsContext2D();
        pw = gc.getPixelWriter();
    }

    @FXML
    public void drawLine(){

        String x1_str = textFieldX1.getText();
        String y1_str = textFieldY1.getText();
        String x2_str = textFieldX2.getText();
        String y2_str = textFieldY2.getText();

        String err = "";
        if (algorithmComboBox.getSelectionModel().getSelectedIndex() == -1) {
            err += "Выберите алгоритм!\n";
        }

        if (x1_str.isEmpty() || x2_str.isEmpty() || y1_str.isEmpty() || y2_str.isEmpty()) {
            err += "Введите координаты!\n";
        }

        if (!err.isEmpty()) {
            showError(err);
            return;
        }

        int x1 = Integer.parseInt(x1_str);
        int y1 = Integer.parseInt(y1_str);
        int x2 = Integer.parseInt(x2_str);
        int y2 = Integer.parseInt(y2_str);

        Line line = new Line(colorPicker.getValue(), pw, gc);
        Long timerStart = 0L;
        Long timerEnd = 0L;
        Timer time = null;
        switch (algorithmComboBox.getSelectionModel().getSelectedIndex()) {
            case 0:
                timerStart = Timer.getCpuTime();
                line.drawDDA(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("DDA", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            case 1:
                timerStart = Timer.getCpuTime();
                line.drawBresenhamFloat(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("BresenhamFloat", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            case 2:
                timerStart = Timer.getCpuTime();
                line.drawBresenhamInteger(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("BresenhamInteger", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            case 3:
                timerStart = Timer.getCpuTime();
                line.drawBresenhamStepSmooth(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("BresenhamStepRemoval", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            case 4:
                timerStart = Timer.getCpuTime();
                line.drawBy(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("By", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            case 5:
                timerStart = Timer.getCpuTime();
                line.drawLib(x1, y1, x2, y2);
                timerEnd = Timer.getCpuTime();
                time = new Timer("Lib", timerEnd - timerStart);
                timeHistory.getTimers().add(time);
                break;
            default:
                throw new RuntimeException("Unhandled case");
        }
    }

    public void drawSun(){
        String xc_str = textFieldXc.getText();
        String yc_str = textFieldYc.getText();
        String angle_str = textFieldDegrees.getText();
        String l_str = textFieldL.getText();

        String err = "";
        if (algorithmComboBox.getSelectionModel().getSelectedIndex() == -1) {
            err += "Выберите алгоритм!\n";
        }

        if (xc_str.isEmpty() || yc_str.isEmpty() || angle_str.isEmpty() || l_str.isEmpty()) {
            err += "Введите координаты!!\n";
        }

        if (!err.isEmpty()) {
            showError(err);
            return;
        }

        int xc = Integer.parseInt(xc_str);
        int yc = Integer.parseInt(yc_str);
        float angle = Float.parseFloat(angle_str);
        int l = Integer.parseInt(l_str);

        Line line = new Line(colorPicker.getValue(), pw, gc);
        final float PI = (float)Math.PI;

        double dx1 = xc - l / 2;
        double dy1 = yc;
        double dx2 = xc + l / 2;
        double dy2 = yc;

        for (int ang = 0; ang <= 180; ang += angle) {
            double x1_tmp = xc + (dx1 - xc) * Math.cos(angle * PI / 180) - (dy1 - yc) * Math.sin(angle * PI / 180);
            double y1_tmp = yc + (dx1 - xc) * Math.sin(angle * PI / 180) + (dy1 - yc) * Math.cos(angle * PI / 180);
            double x2_tmp = xc + (dx2 - xc) * Math.cos(angle * PI / 180) - (dy2 - yc) * Math.sin(angle * PI / 180);
            double y2_tmp = yc + (dx2 - xc) * Math.sin(angle * PI / 180) + (dy2 - yc) * Math.cos(angle * PI / 180);

            dx1 = x1_tmp;
            dy1 = y1_tmp;
            dx2 = x2_tmp;
            dy2 = y2_tmp;

            int x1 = (int)x1_tmp;
            int y1 = (int)y1_tmp;
            int x2 = (int)x2_tmp;
            int y2 = (int)y2_tmp;

            switch (algorithmComboBox.getSelectionModel().getSelectedIndex()) {
                case 0:
                    line.drawDDA(x1, y1, x2, y2);
                    break;
                case 1:
                    line.drawBresenhamFloat(x1, y1, x2, y2);
                    break;
                case 2:
                    line.drawBresenhamInteger(x1, y1, x2, y2);
                    break;
                case 3:
                    line.drawBresenhamStepSmooth(x1, y1, x2, y2);
                    break;
                case 4:
                    line.drawBy(x1, y1, x2, y2);
                    break;
                case 5:
                    line.drawLib(x1, y1, x2, y2);
                    break;
                default:
                    throw new RuntimeException("Unhandled case");
            }
        }
    }
    @FXML
    public void showTime() {
        Alert timeInfo = new Alert(Alert.AlertType.INFORMATION);
        timeInfo.setTitle("Time History");
        timeInfo.setContentText(timeHistory.getFormatedHistory());
        timeInfo.showAndWait();
    }

    @FXML
    public void clearTime() {
        timeHistory.getTimers().clear();
    }

    private void showError(String msg) {
        Alert error = new Alert(Alert.AlertType.ERROR);
        error.setTitle("ERROR");
        error.setHeaderText("OOPS Something happened");
        error.setContentText(msg);

        error.showAndWait();
    }

    @FXML
    public void clearCanvas() {
        gc.clearRect(0, 0, canvasWidth, canvasHeight);
    }

    @FXML
    public void creditsMsg(){
        Alert credits = new Alert(Alert.AlertType.INFORMATION);
        credits.setTitle("Credits");
        credits.setHeaderText("INFORMATION");
        credits.setContentText("MADE BY ALEXANDR CHAUSHEV!!");

        credits.showAndWait();
    }
}

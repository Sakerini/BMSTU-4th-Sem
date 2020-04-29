package com.computergraphics.lab04.fxcontrollers;

import com.computergraphics.lab04.geometry.*;
import com.computergraphics.lab04.timer.Timer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

import java.net.URL;
import java.util.ResourceBundle;

public class FXUIController implements Initializable {

    @FXML public Canvas canvas;
    @FXML public ComboBox<String> algorithmComboBox;
    @FXML public ColorPicker colorPicker;

    @FXML public TextField xcTextField;
    @FXML public TextField ycTextField;
    @FXML public TextField rxTextField;
    @FXML public TextField ryTextField;

    @FXML public TextField xcSpectreTextField;
    @FXML public TextField ycSpectreTextField;
    @FXML public TextField rxSpectreTextField;
    @FXML public TextField rySpectreTextField;
    @FXML public TextField dxSpectreTextField;
    @FXML public TextField dySpectreTextField;
    @FXML public TextField nSpectreTextField;

    @FXML public Label ryLabel;
    @FXML public Label rySpectreLabel;
    @FXML public Label dySpectreLabel;

    @FXML public RadioButton ellipseRadioButton;
    @FXML RadioButton circleRadioButton;

    private double canvasH;
    private double canvasW;
    private GraphicsContext gc;
    private PixelWriter pixelWriter;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        ObservableList<String> list = FXCollections.observableArrayList(
                "Каноническое уравнение",
                "Параметрическое уравнение",
                "Алгоритм Брезенхема",
                "Алгоритм средней точке",
                "Библиотечная функция"
        );

        algorithmComboBox.setItems(list);

        canvasH = canvas.getHeight();
        canvasW = canvas.getWidth();
        gc = canvas.getGraphicsContext2D();
        pixelWriter = gc.getPixelWriter();

        System.out.println("Canvas width: " + canvasW);
        System.out.println("Canvas height: " + canvasH);

    }

    @FXML
    public void selectCircle() {
        chageEllipseVisibilityFields(false);
    }

    @FXML
    public void selectEllipse() {
        chageEllipseVisibilityFields(true);
    }

    @FXML
    public void drawFigure() {
        String xc_str = xcTextField.getText();
        String yc_str = ycTextField.getText();
        String rx_str = rxTextField.getText();
        String ry_str = "";
        if (ellipseRadioButton.isSelected())
            ry_str = ryTextField.getText();

        String err = "";
        if (algorithmComboBox.getSelectionModel().getSelectedIndex() == -1) {
            err += "Выберите алгоритм!\n";
        }

        if (xc_str.isEmpty() ||
            yc_str.isEmpty() ||
            rx_str.isEmpty() ||
                (ry_str.isEmpty() && ellipseRadioButton.isSelected())) {
            err += "Введите все поля!";
        }

        if (!err.isEmpty()) {
            showError(err);
            return;
        }

        int xc = Integer.parseInt(xc_str);
        int yc = Integer.parseInt(yc_str);
        int rx = Integer.parseInt(rx_str);
        int ry = 0;
        if (ellipseRadioButton.isSelected())
            ry = Integer.parseInt(ry_str);

        BasePixelWriterWorker basePixelWriterWorker = null;
        StandartWorker standartWorker = null;
        Color color = colorPicker.getValue();


        int selectedIndex = algorithmComboBox.getSelectionModel().getSelectedIndex();
        switch (selectedIndex) {
            case 0:
                basePixelWriterWorker = new CanonEq(pixelWriter, color);
                break;
            case 1:
                basePixelWriterWorker = new ParamEq(pixelWriter, color);
                break;
            case 2:
                basePixelWriterWorker = new Brezenham(pixelWriter, color);
                break;
            case 3:
                basePixelWriterWorker = new MiddlePoint(pixelWriter, color);
                break;
            case 4:
                standartWorker = new StandartWorker(gc, color);
                break;
            default:
                throw new RuntimeException("Unhandled case");
        }

        if (selectedIndex != 4) {
            if (circleRadioButton.isSelected()) {
                basePixelWriterWorker.drawCircle(xc, yc, rx);
            } else if (ellipseRadioButton.isSelected()) {
                basePixelWriterWorker.drawEllipse(xc, yc, rx, ry);
            }
        } else {
            if (circleRadioButton.isSelected()) {
                standartWorker.drawCircle(xc, yc, rx);
            } else if (ellipseRadioButton.isSelected()){
                standartWorker.drawEllipse(xc, yc, rx, ry);
            }
        }
    }

    @FXML
    public void drawSpectre() {
        String xc_str = xcSpectreTextField.getText();
        String yc_str = ycSpectreTextField.getText();
        String rx_str = rxSpectreTextField.getText();
        String n_str = nSpectreTextField.getText();
        String dx_str = dxSpectreTextField.getText();

        String ry_str = "";
        String dy_str = "";
        if (ellipseRadioButton.isSelected()) {
            ry_str = rySpectreTextField.getText();
            dy_str = dySpectreTextField.getText();
        }

        String err = "";
        if (algorithmComboBox.getSelectionModel().getSelectedIndex() == -1) {
            err += "Выберите алгоритм!\n";
        }

        if (xc_str.isEmpty() ||
                yc_str.isEmpty() ||
                rx_str.isEmpty() ||
                (ellipseRadioButton.isSelected() &&
                        (ry_str.isEmpty() || dy_str.isEmpty()))) {
            err += "Введите все поля!";
        }

        if (!err.isEmpty()) {
            showError(err);
            return;
        }


        int xc = Integer.parseInt(xc_str);
        int yc = Integer.parseInt(yc_str);
        int rx = Integer.parseInt(rx_str);
        int n = Integer.parseInt(n_str);
        int dx = Integer.parseInt(dx_str);

        if ( n<= 0) {
            showError("n should be > 0");
        }

        int ry = 0;
        int dy = 0;
        if (ellipseRadioButton.isSelected()) {
            ry = Integer.parseInt(ry_str);
            dy = Integer.parseInt(dy_str);
        }

        BasePixelWriterWorker basePixelWriterWorker = null;
        StandartWorker standartWorker = null;
        Color color = colorPicker.getValue();


        int selectedIndex = algorithmComboBox.getSelectionModel().getSelectedIndex();
        switch (selectedIndex) {
            case 0:
                basePixelWriterWorker = new CanonEq(pixelWriter, color);
                break;
            case 1:
                basePixelWriterWorker = new ParamEq(pixelWriter, color);
                break;
            case 2:
                basePixelWriterWorker = new Brezenham(pixelWriter, color);
                break;
            case 3:
                basePixelWriterWorker = new MiddlePoint(pixelWriter, color);
                break;
            case 4:
                standartWorker = new StandartWorker(gc, color);
                break;
            default:
                throw new RuntimeException("Unhandled case");
        }

        if (selectedIndex != 4) {
            if (circleRadioButton.isSelected()) {
                basePixelWriterWorker.drawSpectreCircle(xc, yc, rx, dx, n);
            } else if (ellipseRadioButton.isSelected()) {
                basePixelWriterWorker.drawSpectreEllipse(xc, yc, rx, ry, dx, dy, n);
            }
        } else {
            if (circleRadioButton.isSelected()) {
                standartWorker.drawSpectreCircle(xc, yc, rx, dx, n);
            } else if (ellipseRadioButton.isSelected()){
                standartWorker.drawSpectreEllipse(xc, yc, rx, ry, dx, dy, n);
            }
        }
    }

    /* TODO
    @FXML
    public void showTime() {

    }
     */

    @FXML
    public void clearCanvas() {
        gc.clearRect(0, 0, canvasW, canvasH);
    }

    private void showError(String msg) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Ошибка!");
        alert.setHeaderText("Произошла ошибка!");
        alert.setContentText(msg);

        alert.showAndWait();
    }

    private void chageEllipseVisibilityFields(Boolean isViseble) {
        ryTextField.setVisible(isViseble);
        ryTextField.setVisible(isViseble);
        rySpectreTextField.setVisible(isViseble);
        dySpectreTextField.setVisible(isViseble);

        ryLabel.setVisible(isViseble);
        rySpectreLabel.setVisible(isViseble);
        dySpectreLabel.setVisible(isViseble);
    }
}

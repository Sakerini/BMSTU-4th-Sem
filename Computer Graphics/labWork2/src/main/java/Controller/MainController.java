package Controller;
import History.History;
import Objects.BirdFigure;
import Objects.Point;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

import java.net.URL;
import java.util.ResourceBundle;

public class MainController implements Initializable {

    private final History<BirdFigure> history = new History<BirdFigure>();

    @FXML
    private TextField xRotate;
    @FXML
    private TextField yRotate;
    @FXML
    private TextField rotationAngle;

    @FXML
    private TextField xScale;
    @FXML
    private TextField yScale;
    @FXML
    private TextField kxScale;
    @FXML
    private TextField kyScale;

    @FXML
    private TextField dxTransfer;
    @FXML
    private TextField dyTransfer;
    @FXML
    private Canvas canvas;
    private GraphicsContext gc;

    private double scale = 1;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        gc = canvas.getGraphicsContext2D();

        Point centerCanvas = new Point(canvas.getWidth() / 2, canvas.getHeight() / 2);

        BirdFigure bird = new BirdFigure(centerCanvas,200,200,0);
        history.add(bird);
        bird.drawBird(gc);


        /*
        gc.strokeOval(350, 350, 10, 100);
        gc.translate(-350, -350);
        gc.rotate(30);
        gc.translate(350, 350);
        gc.strokeOval(350, 350, 10, 100);\
         */
    }

    @FXML
    public void rotate() {
        if (xRotate.getText().isEmpty() || yRotate.getText().isEmpty() || rotationAngle.getText().isEmpty()) {
            showError("Введите все необходимые поля!");
            return;
        }

        double x = Double.parseDouble(xRotate.getText());
        double y = Double.parseDouble(yRotate.getText());
        double angle = Double.parseDouble(rotationAngle.getText());

        Point center = new Point(x, y);

        BirdFigure shape = history.getCurr();
        BirdFigure newShape = new BirdFigure(shape.getCenter().rotateTwo(center, angle), shape.getWidth(), shape.getHeight(), shape.getRotationAngle() + angle);

        clear();
        newShape.drawBird(gc);
        history.add(newShape);
    }

    public void transfer() {
        if (dxTransfer.getText().isEmpty() || dyTransfer.getText().isEmpty()) {
            showError("Введите все необходимые поля!");
            return;
        }

        double dx = Double.parseDouble(dxTransfer.getText());
        double dy = Double.parseDouble(dyTransfer.getText());

        BirdFigure shape = history.getCurr();
        BirdFigure newShape = new BirdFigure(shape.getCenter().add(dx, dy),
                shape.getWidth(), shape.getHeight(), shape.getRotationAngle());

        clear();
        newShape.drawBird(gc);

        history.add(newShape);
    }

    @FXML
    public void zoomIn() {
        if (xScale.getText().isEmpty() || yScale.getText().isEmpty() ||
                kxScale.getText().isEmpty() || kyScale.getText().isEmpty()) {
            showError("FILL ALL NEEDED ENTRIES!!!");
            return;
        }


        double x = Double.parseDouble(xScale.getText());
        double y = Double.parseDouble(yScale.getText());

        double kx = Double.parseDouble(kxScale.getText());
        double ky = Double.parseDouble(kyScale.getText());

        Point center = new Point(x, y);

        BirdFigure currentBird = history.getCurr();
        BirdFigure newBird = new BirdFigure(currentBird.getCenter().scale(center, kx, ky),
                currentBird.getWidth() * kx, currentBird.getHeight() * ky, currentBird.getRotationAngle());

        clear();
        newBird.drawBird(gc);
        history.add(newBird);
    }

    @FXML
    public void historyPrev() {
        BirdFigure shape = history.getPrev();
        if (shape != null) {
            clear();
            shape.drawBird(gc);
        } else {
            showError("Can not show prev");
        }
        System.out.println("hi");
    }

    @FXML
    public void historyFirst() {
        BirdFigure shape = history.getFirst();
        if (shape != null) {
            clear();
            shape.drawBird(gc);
        } else {
            showError("Can not show first");
        }
    }

    @FXML
    public void historyNext() {
        BirdFigure shape = history.getNext();
        if (shape != null) {
            clear();
            shape.drawBird(gc);
        } else {
            showError("Can not show next");
        }
    }

    @FXML
    public void historyLast() {
        BirdFigure shape = history.getLast();
        if (shape != null) {
            clear();
            shape.drawBird(gc);
        } else {
            showError("Can not show last");
        }

    }
    private void clear() {
        gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
    }

    private void showError(String msg) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("ERROR!");
        alert.setHeaderText("ERROR!!!");
        alert.setContentText(msg);

        alert.showAndWait();
    }
}

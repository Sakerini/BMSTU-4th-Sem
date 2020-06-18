package com.computergraphic.lab10.fxcontroller;

import com.computergraphic.lab10.geometry.FloatHorizont;
import com.computergraphic.lab10.geometry.Func;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.image.PixelWriter;
import javafx.scene.input.DragEvent;
import javafx.scene.paint.Paint;

import java.net.URL;
import java.util.ResourceBundle;

public class FXMainController implements Initializable {

    @FXML
    private Canvas canvas;
    @FXML
    private ChoiceBox<String> function;

    @FXML
    private TextField xMin;
    @FXML
    private TextField xMax;
    @FXML
    private TextField xStep;

    @FXML
    private TextField zMin;
    @FXML
    private TextField zMax;
    @FXML
    private TextField zStep;

    @FXML
    private Slider xRotate;
    @FXML
    private Slider yRotate;
    @FXML
    private Slider zRotate;
    @FXML
    private Slider scale;

    private final FloatHorizont algo = new FloatHorizont();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        // Move (0, 0) to the center of the screen
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.translate(canvas.getWidth() / 2, canvas.getHeight() / 2);
        gc.strokeLine(-20, 0, 20, 0);
        gc.strokeLine(0, -20, 0, 20);

        var funcs = function.getItems();
        funcs.add("cos(x) * sin(z)");
        funcs.add("exp(sin(sqrt(x^2 + z^2)))");
        funcs.add("x^2 / 20 + z^2 / 20");
        funcs.add("x^2 - z^2");
        function.getSelectionModel().select(0);

        xMin.setText("-5");
        xMax.setText("5");
        xStep.setText("0.08");

        zMin.setText("-5");
        zMax.setText("5");
        zStep.setText("0.10");
        setAlgoData();

        // Setup sliders
        initListeners();
    }

    private void initListeners() {
        xRotate.valueProperty().addListener(new ChangeListener() {
            @Override
            public void changed(ObservableValue observable, Object oldValue, Object newValue) {
                algo.setRotationX(Math.toRadians(xRotate.getValue() * 3.6));
                algo.draw();
            }
        });
        yRotate.valueProperty().addListener(new ChangeListener() {
            @Override
            public void changed(ObservableValue observable, Object oldValue, Object newValue) {
                algo.setRotationY(Math.toRadians(yRotate.getValue() * 3.6));
                algo.draw();
            }
        });
        zRotate.valueProperty().addListener(new ChangeListener() {
            @Override
            public void changed(ObservableValue observable, Object oldValue, Object newValue) {
                algo.setRotationZ(Math.toRadians(zRotate.getValue() * 3.6));
                algo.draw();
            }
        });

        scale.valueProperty().addListener(new ChangeListener() {
            @Override
            public void changed(ObservableValue observable, Object oldValue, Object newValue) {
                algo.setScale(scale.getValue() * 0.4);
                algo.draw();
            }
        });
    }

    private void setAlgoData() {
        double xMin = Double.parseDouble(this.xMin.getText());
        double xMax = Double.parseDouble(this.xMax.getText());
        double xStep = Double.parseDouble(this.xStep.getText());

        double zMin = Double.parseDouble(this.zMin.getText());
        double zMax = Double.parseDouble(this.zMax.getText());
        double zStep = Double.parseDouble(this.zStep.getText());

        algo.setXs(xMin, xMax, xStep);
        algo.setZs(zMin, zMax, zStep);
        switch (function.getSelectionModel().getSelectedIndex()) {
            case 0:
                algo.setFunc((x, z) -> Math.cos(x) * Math.sin(z));
                System.out.println(0);
                break;
            case 1:
                algo.setFunc((x, z) -> Math.exp(Math.sin(Math.sqrt(x * x + z * z))));
                System.out.println(1);
                break;
            case 2:
                algo.setFunc((x, z) -> x * x / 20 + z * z / 20);
                System.out.println(2);
            case 3:
                algo.setFunc((x, z) -> x * x - z * z);
                System.out.println(3);
                break;
                default:
                    System.out.println("DEAFAULT CASE");
        }
        algo.setGraphicContext(canvas.getGraphicsContext2D());
    }


    @FXML
    public void execute() {
        setAlgoData();
        algo.draw();
    }
}

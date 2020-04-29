package com.computergraphics.lab04;

import com.computergraphics.lab04.geometry.Brezenham;
import com.computergraphics.lab04.timer.Timer;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Computer graphics - lab_04");

        Parent root = null;
        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("UI.fxml"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        if (root != null) {
            Scene scene = new Scene(root);

            primaryStage.setScene(scene);
        }
        primaryStage.show();
    }
}

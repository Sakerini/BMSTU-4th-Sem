package com.computergraphic.lab10;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    public static void main(String[] args) { launch(args); }

    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Computer graphic - lab_10");

        Parent root = null;
        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("Main.fxml"));
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

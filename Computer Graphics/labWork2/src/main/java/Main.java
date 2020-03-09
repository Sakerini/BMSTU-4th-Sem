import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("LabWork#2");
        stage.setResizable(true);

        Parent root = null;
        try{
            root = FXMLLoader.load(getClass().getClassLoader().getResource("Main.fxml"));
        }catch (IOException e) {
            throw new RuntimeException(e);
        }

        if (root != null) {
            Scene scene = new Scene(root);

            stage.setScene(scene);
        }
        stage.show();
    }
}

import Drawer.Line;
import Timer.TimeHistory;
import Timer.Timer;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {

    interface LineAlgo {
        void alg(int x1, int y1, int x2, int y2);
    }

    private void testTimes() {
        Line line = new Line(Color.BLACK, null, null);
        System.out.println("\nbrezenhame float " + testTime(line::drawBresenhamInteger));
        System.out.println("brezenhame integer " + testTime(line::drawBresenhamFloat));
        System.out.println("brezenhame smooth " + testTime(line::drawBresenhamStepSmooth));
        System.out.println("DDA " + testTime(line::drawDDA));
        System.out.println("By " + testTime(line::drawBy));

    }

    private long testTime(LineAlgo algo) {
        long time = 0;

        for (int i = 0; i < 20; i++) {

            long currTime = Timer.getCpuTime();
            algo.alg(0, 0, 500, 500);
            if (i < 5) continue;
            time += Timer.getCpuTime() - currTime;
        }

        time /= 15;

        return time;
    }

    @Override
    public void start(Stage stage) throws Exception {
        testTimes();
        stage.setTitle("Lab Work#3");

        Parent root = null;
        try {
            root = FXMLLoader.load(getClass().getClassLoader().getResource("ui.fxml"));
        } catch (IOException e) {
            throw new RuntimeException();
        }

        if (root != null) {
            Scene scene = new Scene(root);
            stage.setScene(scene);
        }

        stage.show();
    }
}

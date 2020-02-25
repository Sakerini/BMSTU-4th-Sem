package controllers;

import javafx.beans.binding.Bindings;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.util.Callback;
import javafx.util.converter.DoubleStringConverter;
import objects.*;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class MainController implements Initializable{
    // Table
    @FXML
    public TableView<Point> pointsSet1;
    @FXML
    public TableColumn<Point, Double> cellX1;
    @FXML
    public TableColumn<Point, Double> cellY1;
    @FXML
    public TableView<Point> pointsSet2;
    @FXML
    public TableColumn<Point, Double> cellX2;
    @FXML
    public TableColumn<Point, Double> cellY2;

    //TextFields(a.k.a Entries)
    @FXML
    public TextField inputFieldX;
    @FXML
    public TextField inputFieldY;

    @FXML
    public ComboBox<String> comboBox;

    @FXML
    public Canvas canvas;
    @FXML
    public TextArea messenger;

    public void showInfo(){
        Alert infoMSG = new Alert(Alert.AlertType.INFORMATION);
        infoMSG.setTitle("INFORMATION");
        infoMSG.setHeaderText("Created by Alexandr Chaushev!!");
        TextArea area = new TextArea("On a Surface are given many points. Find a pair of circles, each of which passes through\n" +
                "at least three different points of the same set \n" +
                "such that the difference in the area of the\n" +
                "quadrangles touches the internal common\n" +
                "tangents and the intersection point of the tangents is minimal\n");

        area.setWrapText(true);
        area.setEditable(false);

        infoMSG.getDialogPane().setContent(area);
        infoMSG.setResizable(true);
        infoMSG.showAndWait();
    }
    public static void giveErrorAlert(String msg){
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Ooops somthing went wrong!!!");
        alert.setHeaderText("Error");
        TextArea area = new TextArea(msg);

        area.setWrapText(true);
        area.setEditable(false);

        alert.getDialogPane().setContent(area);
        alert.setResizable(true);
        alert.showAndWait();
    }

    public void addPoint(ActionEvent event) {
        if (inputFieldX.getText().isEmpty() || inputFieldY.getText().isEmpty()) {
            giveErrorAlert("ERROR: Empty text input fields, please check your input");
        } else {
            if (comboBox.getSelectionModel().isEmpty()) {
                giveErrorAlert("ERROR: Table set not chosen, please chose table set for input");
            } else if (comboBox.getSelectionModel().getSelectedIndex() == 0) {
                String x = inputFieldX.getText();
                String y = inputFieldY.getText();

                ObservableList<Point> data = pointsSet1.getItems();
                boolean contains = false;
                for (var item: data) {
                    if (item.getX() == Double.parseDouble(x) && item.getY() == Double.parseDouble(y)) {
                        contains = true;
                    }
                }

                if (!contains){
                    try {
                        data.add(new Point(Double.parseDouble(x), Double.parseDouble(y)));
                    } catch (Exception e){
                        giveErrorAlert("ERROR: no char symbols allowed in points input!!!");
                    }
                }

                //clear the last input
                inputFieldX.setText("");
                inputFieldY.setText("");

            } else if (comboBox.getSelectionModel().getSelectedIndex() == 1) {
                String x = inputFieldX.getText();
                String y = inputFieldY.getText();

                ObservableList<Point> data = pointsSet2.getItems();
                try {
                    data.add(new Point(Double.parseDouble(x), Double.parseDouble(y)));
                }catch (Exception e){
                    giveErrorAlert("ERROR: no char symbols allowed in points input!!!");
                }
                //clear the last input
                inputFieldX.setText("");
                inputFieldY.setText("");
            }
        }
    }

    private void setupEditCells() {
        EventHandler<TableColumn.CellEditEvent<Point, Double>> event = new EventHandler<TableColumn.CellEditEvent<Point, Double>>() {
            @Override
            public void handle(TableColumn.CellEditEvent<Point, Double> event) {
                Point p = (Point) event.getTableView().getItems().get(event.getTablePosition().getRow());
                int column = event.getTablePosition().getColumn();
                if (column == 0) {
                    p.setX(event.getNewValue());
                } else {
                    p.setY(event.getNewValue());
                }
                event.getTableView().refresh();
            }
        };

        cellX1.setCellFactory(TextFieldTableCell.<Point, Double>forTableColumn(new DoubleStringConverter()));
        cellX1.setOnEditCommit(event);

        cellY1.setCellFactory(TextFieldTableCell.<Point, Double>forTableColumn(new DoubleStringConverter()));
        cellY1.setOnEditCommit(event);

        cellX2.setCellFactory(TextFieldTableCell.<Point, Double>forTableColumn(new DoubleStringConverter()));
        cellX2.setOnEditCommit(event);

        cellY2.setCellFactory(TextFieldTableCell.<Point, Double>forTableColumn(new DoubleStringConverter()));
        cellY2.setOnEditCommit(event);
    }

    private void setupDeleteRows() {
        Callback<TableView<Point>, TableRow<Point>> callback = new Callback<TableView<Point>, TableRow<Point>>() {
            @Override
            public TableRow<Point> call(TableView<Point> tableView) {
                final TableRow<Point> row = new TableRow<>();
                final ContextMenu contextMenu = new ContextMenu();

                MenuItem removeItem = new MenuItem("Delete");

                removeItem.setOnAction(new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        tableView.getItems().remove(tableView.getFocusModel().getFocusedCell().getRow());
                    }
                });

                contextMenu.getItems().addAll(removeItem);
                row.contextMenuProperty().bind(
                        Bindings.when(Bindings.isNotNull(row.itemProperty()))
                                .then(contextMenu)
                                .otherwise((ContextMenu)null));

                return row;
            }
        };

        pointsSet1.setRowFactory(callback);
        pointsSet2.setRowFactory(callback);
    }

    public void clearTable(){
        pointsSet1.getItems().clear();
        pointsSet2.getItems().clear();
    }

    public void clearCanvas() {
        canvas.getGraphicsContext2D().clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
    }

    private Point getMin(List<Point> points) {
        if (points.isEmpty()) {
            return null;
        }

        Point min = Point.getCopy(points.get(0));
        for (var point: points) {
            if (point.getX() < min.getX()) {
                min.setX(point.getX());
            }

            if (point.getY() < min.getY()) {
                min.setY(point.getY());
            }
        }

        return min;
    }

    private Point getMax(List<Point> points) {
        if (points.isEmpty()) {
            return null;
        }

        Point max = Point.getCopy(points.get(0));
        for (var point: points) {
            if (point.getX() > max.getX()) {
                max.setX(point.getX());
            }

            if (point.getY() > max.getY()) {
                max.setY(point.getY());
            }
        }

        return max;
    }

    public void draw(ActionEvent event){
        System.out.println("Drawing Started");
        messenger.setText("Message:");

        ObservableList<Point> pointsList1 = pointsSet1.getItems();
        ObservableList<Point> pointsList2 = pointsSet2.getItems();
        /*

        pointsList1.add(new Point(1,5));
        pointsList1.add(new Point(-5,0));
        pointsList1.add(new Point(3,9));
        pointsList1.add(new Point(1,2));
        pointsList1.add(new Point(6,2));
        pointsList1.add(new Point(-1,6));

        pointsList2.add(new Point(6,42));
        pointsList2.add(new Point(-5,12));
        pointsList2.add(new Point(21,22));
        pointsList2.add(new Point(1,11));
        pointsList2.add(new Point(5,6));
        pointsList2.add(new Point(-1,8));

         */

        if (pointsList1.isEmpty() || pointsList2.isEmpty()){
            giveErrorAlert("One of the List is empty!!!");
            return;
        } else if (pointsList1.size() <= 2 || pointsList2.size() <= 2){
            giveErrorAlert("One of the List is empty");
            return;
        }

        Picture pictureToDraw = Calculation.solve(pointsList1, pointsList2);
        if (pictureToDraw == null) {
            //giveErrorAlert("ERROR: Could'not find circles that match the result needed");
            return;
        }
        pictureToDraw.showInfo();
        Line OT1 = new Line(pictureToDraw.getCircleOne().getCentr(),pictureToDraw.getTangentOne().getPointA());
        Line OT2 = new Line(pictureToDraw.getCircleOne().getCentr(),pictureToDraw.getTangentTwo().getPointA());

        Line OT3 = new Line(pictureToDraw.getCircleTwo().getCentr(),pictureToDraw.getTangentOne().getPointB());
        Line OT4 = new Line(pictureToDraw.getCircleTwo().getCentr(),pictureToDraw.getTangentTwo().getPointB());

        //Drawing

        clearCanvas();
        gc.setLineWidth(1.);

        // Drawing Starts Here

        Point min = getMin(pictureToDraw.getAllPoints());
        Point max = getMax(pictureToDraw.getAllPoints());

        System.out.println("MIN POINT: ");
        min.showInfo();
        System.out.println("MAX POINT: ");
        max.showInfo();
        dx = -min.getX();
        dy = -min.getY();

        x_scale = 1;
        y_scale = 1;
        if (Math.abs(max.getX() - min.getX()) > 1e-10) {
            x_scale = (width - padding) / (max.getX() - min.getX());
        }

        if (Math.abs(max.getY() - min.getY()) > 1e-10) {
            y_scale = (height - padding) / (max.getY() - min.getY());
        }

        if (x_scale > y_scale) {
            x_scale = y_scale;
        } else {
            y_scale = x_scale;
        }
        messengerSetup(pictureToDraw);
        drawCircle(pictureToDraw.getCircleOne());
        drawCircle(pictureToDraw.getCircleTwo());
        drawLines(pictureToDraw.getTangentOne());
        drawLines(pictureToDraw.getTangentTwo());
        drawLines(OT1);
        drawLines(OT2);
        drawLines(OT3);
        drawLines(OT4);

    }
    public void messengerSetup(Picture pictureToDraw){
        StringBuilder sb = new StringBuilder();
        //Information about first Circle
        sb.append("Circle1:\n"); sb.append("Build on:"); sb.append(Point.getStringPoints(pictureToDraw.getPointList1().get(0), " A"));
        sb.append(Point.getStringPoints(pictureToDraw.getPointList1().get(1), " B"));
        sb.append(Point.getStringPoints(pictureToDraw.getPointList1().get(2), " C"));
        sb.append("\n"); sb.append(Point.getStringPoints(pictureToDraw.getCircleOne().getCentr(), "Center:"));
        sb.append(" Radius: " + String.format("%.2f", pictureToDraw.getCircleOne().getRadius()));

        //Information about second circle
        sb.append("\n");sb.append("Circle2:\n");sb.append("Build on");
        sb.append(Point.getStringPoints(pictureToDraw.getPointList2().get(0), " D"));
        sb.append(Point.getStringPoints(pictureToDraw.getPointList2().get(1), " E"));
        sb.append(Point.getStringPoints(pictureToDraw.getPointList2().get(2), " F"));
        sb.append("\n"); sb.append(Point.getStringPoints(pictureToDraw.getCircleTwo().getCentr(), "Center:"));
        sb.append(" Radius: " + String.format("%.2f", pictureToDraw.getCircleTwo().getRadius()));
        //Intersection point
        sb.append("\n"); sb.append("Inner Tangents Intersection:");
        sb.append(Point.getStringPoints(pictureToDraw.getIntersectionPoint(), " I"));
        //Difference in Square
        sb.append("\nDifference in Squares: "); sb.append(String.format("%.2f", pictureToDraw.getSquareRoot()));


        String resultText = sb.toString();
        messenger.setText(resultText);
    }

    private void convertCoordinates(Point point) {
        point.setX((point.getX() + dx) * x_scale + padding / 2);
        point.setY(-((point.getY() + dy) * y_scale + padding / 2) + height);
    }

    public void drawCircle(MyCircle circle){
        Point centrTMP = new Point(circle.getCentr().getX(), circle.getCentr().getY());
        convertCoordinates(centrTMP);
        double radius = circle.getRadius();
        double xRadius = radius * x_scale;
        double yRadius = radius * y_scale;

        gc.strokeOval(centrTMP.getX() - xRadius,centrTMP.getY() - yRadius, xRadius * 2, yRadius * 2);
    }

    public void drawLines(Line line){
        Point one = new Point(line.getPointA().getX(), line.getPointA().getY());
        Point two = new Point(line.getPointB().getX(),line.getPointB().getY());
        convertCoordinates(one);
        convertCoordinates(two);
        gc.strokeLine(one.getX(), one.getY(), two.getX(), two.getY());
    }

    // Points
    private ObservableList<Point> points1;
    private ObservableList<Point> points2;

    //Graphics window
    private double height;
    private double width;
    private GraphicsContext gc;

    // Scale
    private double x_scale;
    private double y_scale;
    private double dx;
    private double dy;

    //Constants
    private final double padding = 100;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        comboBox.getItems().removeAll(comboBox.getItems());
        comboBox.getItems().addAll("Table Set 1", "Table Set 2");


        points1 = pointsSet1.getItems();
        points2 = pointsSet2.getItems();

        height = canvas.getHeight();
        width = canvas.getWidth();
        gc = canvas.getGraphicsContext2D();

        pointsSet1.setEditable(true);
        pointsSet2.setEditable(true);

        setupEditCells();
        setupDeleteRows();


    }
}

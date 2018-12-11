package sample;

import javafx.scene.control.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.cell.PropertyValueFactory;
import java.util.Objects;

public class Controller {
    private ObservableList<Book> Data = FXCollections.observableArrayList();

    @FXML
    private TableView<Book> table = new TableView<>();

    @FXML
    private TableColumn<Book, Integer> idC;

    @FXML
    private TableColumn<Book, String> fromC;

    @FXML
    private TableColumn<Book, String> toC;

    @FXML
    private TableColumn<Book, String> dateC;

    @FXML
    private TableColumn<Book, String> timeC;

    @FXML
    private TableColumn<Book, Double> durationC;

    @FXML
    private void initialize() {
        initData();
        idC.setCellValueFactory(new PropertyValueFactory<>("id"));
        fromC.setCellValueFactory(new PropertyValueFactory<>("from"));
        toC.setCellValueFactory(new PropertyValueFactory<>("to"));
        dateC.setCellValueFactory(new PropertyValueFactory<>("date"));
        timeC.setCellValueFactory(new PropertyValueFactory<>("time"));
        durationC.setCellValueFactory(new PropertyValueFactory<>("duration"));
        table.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
        table.setItems(Data);
    }

    @FXML
    public void Search(ActionEvent event) {
        TextField source = (TextField) event.getSource();

        for (int i = 0; i < table.getItems().size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (Objects.equals(table.getItems().get(i).getAll()[j].toString().toLowerCase(), source.getText().toLowerCase())) {
                    table.requestFocus();
                    table.getSelectionModel().select(i);
                }
            }
        }
    }

    @FXML
    public void Input() {
        table.getSelectionModel().clearSelection();
    }

    private void initData() {
        Data.addAll(new Book(1, "Петр", "Аркадий", "24.11.2018", "17:47" ,25));
        Data.addAll(new Book(2, "Анна", "Алена", "22.11.2018", "4:13" ,16));
        Data.addAll(new Book(3, "Екатерина", "Максим", "23.11.2018", "3:02" ,73));
        Data.addAll(new Book(4, "Альберт", "Михаил", "24.11.2018", "20:25" ,63));
        Data.addAll(new Book(5, "Ярослав", "Марк", "24.11.2018", "03:52" ,33));
        Data.addAll(new Book(6, "Владимир", "Ульяна", "22.11.2018", "10:22" ,58));
        Data.addAll(new Book(7, "Георгий", "Анатолий", "13.11.2018", "12:10" ,16));
        Data.addAll(new Book(8, "Андрей", "Анна", "13.11.2018", "17:05" ,22));
    }
}
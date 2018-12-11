package sample;

public class Book {

    private int id;
    private String from;
    private String to;
    private String date;
    private String time;
    private int duration;

    public Book(int id, String from, String to, String date, String time, int duration) {
        this.id = id;
        this.from = from;
        this.to = to;
        this.date = date;
        this.time = time;
        this.duration = duration;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public Object[] getAll(){
        Object[] arr = new Object[5];
        arr[0] = this.from;
        arr[1] = this.to;
        arr[2] = this.date;
        arr[3] = this.time;
        arr[4] = this.duration;
        return arr;
    }
}

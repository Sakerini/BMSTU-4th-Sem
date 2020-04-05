package Timer;

import java.util.ArrayList;

public class TimeHistory {
    private ArrayList<Timer> timers = new ArrayList<Timer>();

    public TimeHistory(ArrayList<Timer> timersList){
        this.timers = timersList;
    }

    public ArrayList<Timer> getTimers() {
        return timers;
    }

    public String getFormatedHistory(){
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < timers.size(); i++) {
            sb.append(i + 1);
            sb.append(". ");
            sb.append(timers.get(i).getAlghoritmName());
            sb.append(" Time: ");
            sb.append(timers.get(i).getTime());
            sb.append("\n");
        }
        return sb.toString();
    }
}

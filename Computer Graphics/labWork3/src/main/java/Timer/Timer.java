package Timer;

import java.lang.management.ManagementFactory;
import java.lang.management.ThreadMXBean;

public class Timer {

    private String alghoritmName;
    private Long time;

    public Timer(String algName, Long time){
        this.alghoritmName = algName;
        this.time = time;
    }

    public void setAlghoritmName(String alghoritmName) { this.alghoritmName = alghoritmName; }
    public String getAlghoritmName() { return alghoritmName; }

    public void setTime(Long time) { this.time = time; }
    public Long getTime() { return time; }

    public static long getCpuTime() {
        ThreadMXBean bean = ManagementFactory.getThreadMXBean();
        return bean.isCurrentThreadCpuTimeSupported() ?
                bean.getCurrentThreadCpuTime() :
                0L;
    }
}

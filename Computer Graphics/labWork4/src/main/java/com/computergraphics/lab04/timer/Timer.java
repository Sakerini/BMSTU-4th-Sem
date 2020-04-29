package com.computergraphics.lab04.timer;

import com.computergraphics.lab04.Main;
import com.computergraphics.lab04.geometry.Brezenham;
import com.computergraphics.lab04.geometry.CanonEq;
import com.computergraphics.lab04.geometry.MiddlePoint;
import com.computergraphics.lab04.geometry.ParamEq;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;

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

    interface LineAlgo {
        void alg(int x1, int x2, int r);
    }

    private  static long testTime(LineAlgo algo) {
        long time = 0;

        for (int i = 0; i < 20; i++) {

            long currTime = Timer.getCpuTime();
            algo.alg(350, 350, 100);
            if (i < 5) continue;
            time += Timer.getCpuTime() - currTime;
        }

        time /= 15;

        return time;
    }

    public static void testTimes(PixelWriter pw, Color color) {
        Brezenham brezenham = new Brezenham(pw, color);
        System.out.println("\nbrezenhame " + testTime(brezenham::drawCircle));
        CanonEq canonEq = new CanonEq(pw,color);
        System.out.println("\ncacnonEq " + testTime(canonEq::drawCircle));
        ParamEq paramEq = new ParamEq(pw, color);
        System.out.println("\nparam " + testTime(paramEq::drawCircle));
        MiddlePoint middlePoint = new MiddlePoint(pw,color);
        System.out.println("\nMP " + testTime(middlePoint::drawCircle));
    }
}

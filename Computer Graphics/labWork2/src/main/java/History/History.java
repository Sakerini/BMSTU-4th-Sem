package History;

import java.util.ArrayList;

public class History<T> {
    private int curr = -1;

    private final ArrayList<T> buffer = new ArrayList<>();

    public History() {}

    public boolean isEmpty() {
        return buffer.isEmpty();
    }

    public boolean hasPrev() {
        return curr > 0;
    }

    public boolean hasNext() {
        return curr < buffer.size() - 1;
    }

    public T getCurr() {
        if (isEmpty()) {
            return null;
        }

        return buffer.get(curr);
    }

    public T getPrev() {
        if (hasPrev()) {
            curr--;
            return getCurr();
        }

        return null;
    }

    public T getNext() {
        if (hasNext()) {
            curr++;
            return getCurr();
        }

        return null;
    }

    public T getFirst() {
        if (!isEmpty()) {
            curr = 0;
            return getCurr();
        }

        return null;
    }
    public T getLast() {
        if (!isEmpty()) {
            curr = buffer.size() - 1;
            return getCurr();
        }

        return null;
    }

    public void add(T el) {
        while (curr < buffer.size() - 1) {
            buffer.remove(buffer.size() - 1);
        }

        buffer.add(el);
        curr++;
    }
}

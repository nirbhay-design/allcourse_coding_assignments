class Counter{
    public int cnt=0;

    public synchronized void increment(){
        cnt += 1;
    }
}

public class Firsthread{
    public static void main(String[] args) throws Exception {
        // Counter c = new Counter();
        // Thread t1 = new Thread(new Runnable()
        // {
        //     public void run(){
        //         for(int i = 0;i<1000;i++){
        //             c.increment();
        //         }
        //     }
        // });
        // Thread t2 = new Thread(new Runnable()
        // {
        //     public void run(){
        //         for(int i = 0;i<1000;i++){
        //             c.increment();
        //         }
        //     }
        // });
        
        // t1.start();
        // t2.start();

        // t1.join();
        // t2.join();
            // float val = 55/0;
            // System.out.println(val);
        // System.out.println(c.cnt);
        for (int i = 77;i>=0;i += 7){
            System.out.println(i);
        }
    }
}
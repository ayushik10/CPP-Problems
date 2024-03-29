/*  1115. PRINT FooBar ALTERNATIVELY

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

 

Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
 

Constraints:
1 <= n <= 1000
*/



class FooBar {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    bool turn;

public:
    FooBar(int n) {
        this->n = n;
        turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	std::unique_lock<std::mutex>lock(m);

            while(turn == 1)
            cv.wait(lock);

        	printFoo();
            turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	std::unique_lock<std::mutex>lock(m);

            while(turn == 0)
            cv.wait(lock);

        	printBar();
             turn = 0;
            cv.notify_all();
        }
    }
};

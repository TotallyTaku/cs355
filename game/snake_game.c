#include <ncurses.h>
#include <panel.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>


const int FPS = 60;
const char SNAKE_CHARACTER = 'o';
const int WIDTH = 720;
const int HEIGHT = 1280;


int multiplier = 0;

void setup();
void custom_func(int);
void timer_func();
void print_border();

int main (){
    
    setup();
     
    signal(SIGALRM, custom_func);
    clear();
    alarm(5);


    timer_func();
    print_border();
    // HANG BEFORE WINDOW/ GAME TERMINATION
    getch();
    endwin();
    
    return 0;
}


void setup(){

    initscr();      // initialize screen
    clear();        // clear screen of anything
}


void custom_func(int signum){

    mvaddstr(2*multiplier,2*multiplier, "Alarm Triggered");
    multiplier++;
    refresh();
}


void print_border(){

    for (int i=1; i < WIDTH; i++){
        for (int j=1;i < HEIGHT; j++){
            
            // TOP BORDER
            if (i ==1){
                move(j,i);
                addch('#');
            }

            // BOTTOM BORDER
            if (i == WIDTH-1){
                move(j,i);
                addch('#');
            }
        }
        sleep(0.5);
        refresh();
    }
}


void timer_func(){
    struct itimerval timer;
    timer.it_interval.tv_sec = 3;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    
    setitimer(ITIMER_REAL, &timer, NULL);

}
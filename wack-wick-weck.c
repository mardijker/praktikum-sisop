#include <xinu.h>

void P1(void);
void P2(void);
void P3(void);

sid32 s1, s2, s3;

process main(void) {    
    // Membuat semaphores
    s1 = semcreate(1);  // Wick dimulai dari 0 (wait)
    s2 = semcreate(0);   // Weck dimulai dari 0 (wait)
    s3 = semcreate(0);   // Wack dimulai dari 1 (allow to run first)
    
    // Membuat dan mengeksekusi proses
    resume(create(P1, 1024, 20, "wack", 1, s1));
    resume(create(P2, 1024, 20, "wick", 1, s2));
    resume(create(P3, 1024, 20, "weck", 1, s3));
    
    return OK;
}

void P1(void) {
    while (1) {
        wait(s1);
        printf("Wack\n");
        signal(s2);
        sleepms(1000);
    }
}

void P2(void) {
    while (1) {
        wait(s2);
        printf("Wick\n");
        signal(s3);
        sleepms(1000);
    }
}

void P3(void) {
    while (1) {
        wait(s3);
        printf("Weck\n");
        signal(s1);
        sleepms(1000);
    }
}

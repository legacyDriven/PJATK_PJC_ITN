//
// Created by Gienek on 02/04/2023.
//
#include <iostream>
#include <iomanip>

void showPeriod(int period);
int pack(int fromy, int fromm, int fromd,
         int toy, int tom, int tod);

int main() {
    int period = pack(0, 2, 3, 127, 11, 29);
    showPeriod(period);

    return 0;
}

int pack(int fromy, int fromm, int fromd,
         int toy, int tom, int tod) {
    int packed_date = 0;
    packed_date |= (fromy & 0x7F) << 25;
    packed_date |= (fromm & 0xF) << 21;
    packed_date |= (fromd & 0x1F) << 16;
    packed_date |= (toy & 0x7F) << 9;
    packed_date |= (tom & 0xF) << 5;
    packed_date |= (tod & 0x1F);

    return packed_date;
}

void showPeriod(int period) {
    int fromy = (period >> 25) & 0x7F;
    int fromm = (period >> 21) & 0xF;
    int fromd = (period >> 16) & 0x1F;
    int toy = (period >> 9) & 0x7F;
    int tom = (period >> 5) & 0xF;
    int tod = period & 0x1F;

    std::cout << 2000 + fromy << "/" << std::setfill('0') << std::setw(2) << fromm << "/" << std::setw(2) << fromd << "-";
    std::cout << 2000 + toy << "/" << std::setw(2) << tom << "/" << std::setw(2) << tod << std::endl;
}

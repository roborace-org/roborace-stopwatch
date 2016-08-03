#include "MedianFilter.h"

void MedianFilter::readValues() {
    delayMicroseconds(DELAY_BEFORE_READ_MCS);
    for (int i = 0; i < READ_COUNT; ++i) {
        values[i] = sensor->getDistance();
    }
}

template<class T>
void swap(T &a, T &b) {
    T c(a);
    a = b;
    b = c;
}

void MedianFilter::sortValues() {
    int minIndex;
    for (int position = 0; position <= MEDIAN_INDEX; ++position) {
        minIndex = position;

        for (int j = position + 1; j < READ_COUNT; ++j) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }

        if (position != minIndex) {
            swap<short>(values[position], values[minIndex]);
        }
    }
}

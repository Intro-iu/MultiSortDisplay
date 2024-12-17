#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "Sort.hpp"

template <typename T>
class BubbleSort : public Sort<T> {
   public:
    void sort(int speed = 0) override {
        size_t n = this->arr.size();
        for (size_t i = 0; i < n - 1; ++i) {
            this->loopIterations++;  // ���ѭ������
            for (size_t j = 0; j < n - i - 1; ++j) {
                this->loopIterations++;  // �ڲ�ѭ������
                this->comparisons++;
                if (this->arr[j] > this->arr[j + 1]) {
                    this->swap(this->arr[j], this->arr[j + 1]);
                }
                this->display();  // ��ʾ����״̬
                this->delay(speed);
            }
        }
    }
};

#endif

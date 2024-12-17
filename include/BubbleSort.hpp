#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "Sort.hpp"

/**
 * @brief ð�������࣬�̳��� Sort ����
 * @tparam T ��������
 * @tparam DisplayType ���ӻ�����
 */
template <typename T, typename DisplayType = DisplayPic<T>>
class BubbleSort : public Sort<T, DisplayType> {
   public:
    /**
     * @brief ʵ��ð������������㷨
     *
     * @param speed ��������еĶ����ٶȣ���ʱ��
     * @param gui �Ƿ�����ͼ�λ����
     */
    void sort(int speed = 0, bool gui = false) override {
        size_t n = this->arr.size();
        bool swapped;

        // ��ѭ��������������
        for (size_t i = 0; i < n - 1; ++i) {
            swapped = false;

            // ��ѭ����������Ԫ�رȽϺͽ���
            for (size_t j = 0; j < n - i - 1; ++j) {
                this->comparisons++;  // �Ƚϴ�������

                // ��������������ж�
                bool condition = (this->sortOrder == SortOrder::ASCENDING)
                                     ? (this->arr[j] > this->arr[j + 1])
                                     : (this->arr[j] < this->arr[j + 1]);

                // ����Ԫ��
                if (condition) {
                    std::swap(this->arr[j],
                              this->arr[j + 1]);  // ʹ��std::swap���н���
                    swapped = true;
                    this->swaps++;  // ������������
                }

                this->loopIterations++;  // ѭ��������������

                // ��ʾ��ǰ״̬
                if (gui) {
                    this->display();
                    this->delay(speed);
                }
            }

            // ���һ������û�з�����������˵�������Ѿ�������ˣ���ǰ����
            if (!swapped) {
                break;
            }
        }
    }
};

#endif

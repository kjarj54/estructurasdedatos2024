void shakerSort(vector<int>& numbers) {

    bool swapped = true;

    int start = 0;

    int end = numbers.size() - 1;



    while (swapped) {

        swapped = false;

        for (int i = 0; i < end; i++) {

            if (numbers[i] > numbers[i + 1]) {

                int temp = numbers[i];

                numbers[i] = numbers[i + 1];

                numbers[i + 1] = temp;

                swapped = true;

            }

        }



        if (!swapped) break;

        end--;

        swapped = false; 



        for (int j = end; j > start; j--) {

            if (numbers[j] < numbers[j - 1]) {

                int temp = numbers[j];

                numbers[j] = numbers[j-1];

                numbers[j - 1] = temp;

                swapped = true;

            }

        }

        start++;

    }

}
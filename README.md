**BÁO CÁO KẾT QUẢ THỬ NGHIỆM**

**Các thuật toán sắp xếp** 

Thời gian thực hiện: 17/04 – 24/04/2021

**Sinh viên thực hiện: Nguyễn Văn Thành Đạt - 20520436**

**Nội dung báo cáo:**

1. ***Tóm tắt về thuật toán QuickSort***
   1. Ý tưởng
- Thuật toán được cải tiến từ **Interchange Sort** như thuật toán vừa nên tên trên thì ta sẽ đưa tuần tự các số lớn đỗi chỗ với số bên trái dãy số ( hoặc đưa tuần tự các số nhỏ đỗi chỗ với số bên trái dãy số).
- Với trường hợp 3 số giảm dần thì với **Interchange Sort** thì nó sẽ làm 4 bước để sắp xếp thành chuỗi tăng dần.

**Ví dụ:**

\+ 3 2 1

\+ 2 3 1

\+ 1 3 2

\+ 1 2 3

- Thay vì t làm như trên thì t có thể đỗ chõ vị trí 2 số 1 và 3

**Ví dụ:**

**+** 3 2 1

**+** 1 2 3

- Dễ dàng nhận ra được rằng là phương pháp dưới tối ưu hơn. Từ đó ta có ý tưởng về **Quick Sort**. Sau đó ta dùng ý tưởng như trên đã trình bày thì sẽ đưa dãy số thành 2 khoảng gồm 1 khoảng nằm ở trước **Pivot** gồm các số nhỏ hơn số ở vị trí mốc thêm vào số ở vị trí mốc và 1 khoảng nằm phía sau **Pivot** gồm các số lớn hơn số ở vị trí mốc. Làm tuần tự với các khoảng nhỏ đến khi khoảng nhỏ chỉ còn 1 phần tử
  1. Thuật toán
- **Bước 1**: Chọn số nằm ở giữa dãy số làm số mốc để chia mảng thành 2 mảng nằm 2 bên số đó như ý tưởng ở trên gọi là số **Pivot.**
- **Bước 2**: Ta xét chạy 1 biến chạy từ đầu 1 biến chạy từ cuối nếu thỏa vào ý tưởng trên thì sẽ thực hiện theo ý tưởng.
- **Bước 3**: Sau đó ta các bước trên đã trình bày thì sẽ đưa dãy số thành 2 khoảng gồm 

**+** 1 khoảng nằm ở trước **Pivot** gồm các số nhỏ hơn số ở vị trí mốc thêm vào số ở vị trí mốc và 1 khoảng nằm phía sau **Pivot** gồm các số lớn hơn số ở vị trí mốc.

**+** 1 khoảng nằm ở trước **Pivot** gồm các số nhỏ hơn số ở vị trí và 1 khoảng nằm phía sau **Pivot** gồm các số lớn hơn số ở vị trí mốc thêm vào số ở vị trí mốc.

- **Bước 4**: thực hiện lại bước 1, 2, 3 với các khoảng ta đã chia dược ở trên.
  1. Minh họa với ví dụ cụ thể
- Dữ liệu vào: 1 7 4 6 3 2 5

- 1 7 4 6 3 2 5
- 1 2 4 6 3 7 5
- 1 2 4 6 3 7 5 
- 1 2 3 6 4 7 5
- 1 2 3 6 4 7 5
- 1 2 3 6 4 7 5
- 1 2 3 6 4 7 5
- 1 2 3 5 4 7 6
- 1 2 3 5 4 7 6
- 1 2 3 4 5 6 7

- Ta sẽ thu được dãy 1 2 3 4 5 6 7
  1. Cài đặt bằng NNLT cụ thể
```c++
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void QuickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    int pivot = arr[middle];
    int i = left, j = right;
    while (i <= j)
    {

        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(arr, left, j);
    if (right > i)
        QuickSort(arr, i, right);
}
```

` `***2Tóm tắt về thuật toán HeapSort***

1. Ý tưởng
- Thuật toán cải tiến tự thuật toán **Selection Sort** khi ta tuần tự đưa số nhỏ nhất về bên trái ( hoặc số lớn nhất về bên phải ) ta có thể thấy được việc mỗi lần tìm được số nhỏ nhất ta phải quét hết mảng thì giờ đây chúng ta có thể xây dựng 1 cấu trúc “cây nhị phân tuyến tính” là số thứ n nhỏ hơn số thứ 2n+1 và số thứ 2n+2 để tối ưu tìm số nhỏ nhất.
  1. Thuật toán
- Chạy 1 biến n từ cuối dãy lên đầu.
- So sánh theo quy luật số thứ n nhỏ hơn số thứ 2n+1 và số thứ 2n+2.
- Làm tuần tự hết mảng đến khi toàn dãy thõa quy luật số thứ n nhỏ hơn số thứ 2n+1 và số thứ 2n+2.
- Khi đó số nhỏ nhất là số nằm ở vị trí đầu tiên.
- Ta có dãy mới là dãy cũ với n – 1 số hạng không có số hạng đầu tiên của dãy cũ
- Làm lại các bước trên đến khi dãy mới chỉ còn 1 số hạng

  1. Cài đặt bằng NNLT cụ thể
```c++
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

```

***III Kết quả thử nghiệm***

1. ***Bảng kết quả:***

|**Bộ <br>dữ liệu**|**Kích cỡ** |**Thời gian thực hiện (ms)**|<p></p><p>**Tính chất của bộ dữ liệu**</p><p></p>|
| :-: | :-: | :-: | :-: |
|||**QS**|**HS**|**qsort (C)**|**Sort (C++)**||
|1|106|76|2455|494|1378|Nguyên, tăng dần|
|2|106|123|2290|500|1479|Nguyên, giảm dần|
|3|106|935|134|49|92|Nguyên, tất cả bằng nhau|
|4|106|626|2523|575|2132|Nguyên, ngẫu nhiên|
|5|106|642|2659|582|2172|Nguyên, ngẫu nhiên|
|6|106|83|2497|494|1365|Thực, tăng dần|
|7|106|144|2296|497|1468|Thực, giảm dần|
|8|106|1630|133|49|97|Thực, tất cả bằng nhau|
|9|106|1055|2603|499|2249|Thực, ngẫu nhiên|
|10|106|712|2513|549|2282|Thực, ngẫu nhiên|
|Trung bình|106|602.6|2010.3|428.8|1471.4||
1. ***Biểu đồ so sánh:***

![](Aspose.Words.0d393a89-fadb-4c88-b814-3d8a69def930.001.png)
![image](https://user-images.githubusercontent.com/71264853/132713660-2939d01d-f6e6-4196-9fa2-2a94bbfd5be4.png)

- Nhận xét chung:
- Dễ dàng nhận ra được thì Quick Sort thể hiện ưu điểm rõ rệt khi có thời gian nhanh hơn rất nhiều các thuật toán sắp xếp khác ( ví dụ bộ dữ liệu số 1, 2 6,..).
- Các thuật toán có tốc độ nhanh lượt là qSort => Sort => Heap Sort.   
- Nhưng tốc độ trung bình thì qSort có tốc độ vượt trội hơn so với các thuật toán khác tiếp theo lần lượt là Quick Sort, Sort (C++), Heap Sort.
- Ở bộ dữ liệu số 3 và số 8 thì Quick Sort lại có thời gian chạy rất chậm hơn so với các thuật toán khác và bộ dữ liệu số 3 và số 8 là là tất cả các số bằng nhau. Qua đó ta thấy được khi sắp xếp các bộ dự liệu có các phần tử bằng nhau thì không nên dùng Quick Sort để sắp xếp.
- ***Quick Sort***

![image](https://user-images.githubusercontent.com/71264853/132713746-2bec4895-c663-4911-b0c1-7ee0811cd1a4.png)

![](Aspose.Words.0d393a89-fadb-4c88-b814-3d8a69def930.001.png)

- Thời gian chạy bộ dữ liệu số nguyên nhanh hơn hẳn so sánh với bộ dự liệu số thực.
- Sắp xếp nhanh ở bộ số 1, 2, 6, 7 là những bộ dữ liệu có thứ tự vì nó thỏa hầu như với ý tưởng ban đầu.
- Thời gian chạy bộ dữ liệu nguyên nhanh hơn kiểu dữ liệu số thực => Hiệu quả hơn khi dùng với bộ dữ liệu số thực
- ***Heap Sort*** 

![image](https://user-images.githubusercontent.com/71264853/132713770-40e6ecb0-c6eb-4d2d-bc2e-66211f16af4a.png)

![](Aspose.Words.0d393a89-fadb-4c88-b814-3d8a69def930.001.png)

- Với Heap sort thì ngược lại với Quick Sort khi mà bộ dữ liệu có tất cả phần tử bằng nhau thì lại sắp xếp rất nhanh do với ý tưởng ở trên thì Heap Sort thực hiện ít thao tác hơn hẳn so với Quick Sort.
- Còn với các bộ dữ liệu còn lại thì các thời gian sắp xếp xấp xỉ nhau với có thời gian rất lời so với thời gian sắp xếp bộ dữ liệu tất cả các phần tử bằng nhau.
- Thời chạy bộ dữ liệu số nguyên tương đương số thực => kiểu dữ liệu không ảnh hưởng tới thời gian chạy thuật toán

***IV Kết luận:***

- Thời gian chạy các bộ dữ liệu có thứ tự là rất nhanh mà trong thực tế các bộ dữ liệu cần được sắp xếp thường là bộ dữ liệu có thứ tự nên trong thực tế thì hầu như người ta thường dùng Quick Sort để sắp xếp các bộ dữ liệu này.
- Với các bộ dữ liệu có các phần tử bằng nhau thì Quick Sort lại thể hiện tốc độ chậm nên trong thực tế thì với các bộ dữ liệu có giá trị xêm xêm và thường xấp xỉ thì người sẽ không dùng Quick Sort
- Trong với ý tưởng để hình thành nên Heap Sort này thì nó rất phù hợp để tìm ra các số lớn nhất trong mảng vì thế trong thực tế nó thường dùng cho các mảng cần tìm phần tử đặc trưng hoặc có giá trị lớn nhất đặc biệ thường dùng cho các bảng xếp hạng như âm nhanh khi cần phải cập nhật hằng tuần và chỉ cần thể hiện top các bài hát ( top nhiều nhất là 100 phần tử )
- Với các bộ dữ liệu ngẫu nhiên thì hầu như hàm qSort (C) thường có ưu thế về thời gian chạy hơn so với các thuật toán khác nên với các bài toán học thuật hay là xử lý các bộ dữ liệu ngẫu nhiên thì nên dùng qSort

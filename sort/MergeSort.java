import java.util.Arrays;

class MergeSort {
  public static int[] mergeSort(int[] arr) {
    if (arr.length <= 1) {
      return merge(mergeSort(Arrays.copyOfRange(arr, 0, arr.length/2)), mergeSort(Arrays.copyOfRange(arr, arr.length/2, arr.length)));
    }
    return arr;
  }

  private static int[] merge(int[] left, int[] right) {
    int[] arr = new int[left.length + right.length];
    // copy left and right into arr
    int i,j,k; i=j=k=0;
    while (k<arr.length) {
      if (i==left.length) {
        arr[k++] = right[j++];
      }
      if (j==right.length) {
        arr[k++] = left[i++];
      }
      if (left[i] < right[j]) {
        arr[k++] = left[i++];
      } else {
        arr[k++] = right[j++];
      }
    }
    return arr;
  }

  public static void main(String[] args) {
    int[] arr = {5, 4, 3, 2, 1};
    int[] sorted = MergeSort.mergeSort(arr);
    for (int i=0; i<sorted.length; i++) {
      System.out.println(sorted[i]);
    }
  }
}

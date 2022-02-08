import java.util.Arrays;

/**
 * Java has a better support for array operation (e.g. finding the array's length)
 * The implementation is thus shorter and easier to understand
 */
public class IntArrayIndexer {
  private int[] fArrayElements;

  public IntArrayIndexer(int[] aArray) {
    fArrayElements = aArray;
  }

  public int at(String aKey) {
    int lIndex = Integer.parseInt(aKey);

    if (lIndex < fArrayElements.length) {
      return fArrayElements[lIndex];
    } else 
      throw new IndexOutOfBoundsException("Index: " + aKey);
  }

  public static void main(String[] args) {
    int a[] = {1,2,3,4,5,100};
    int len = a.length;
    System.out.println("Creating indexer for array");
    IntArrayIndexer indexer = new IntArrayIndexer(a);

    String keys[] = {"0", "1", "2", "3", "4", "5"};
    int Sum = 0;

    for (int i = 0; i < len; i++) {
      Sum += indexer.at(keys[i]);
    }

    System.out.println("Indexed sum of " +
      Arrays.toString(a) + " is " + Sum);
  }
}
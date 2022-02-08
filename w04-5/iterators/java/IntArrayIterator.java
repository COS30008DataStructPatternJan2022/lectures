import java.util.Iterator;
import java.util.Arrays;
import java.util.NoSuchElementException;

/* Again: Java has a better support for the implementation of IntArrayIterator! */
public class IntArrayIterator implements Iterator<Integer> {
  private int[] fArray;
  private int fIndex;

  public IntArrayIterator(int[] aArray) {
    fArray = aArray;
    fIndex = 0;
  }

  @Override
  public boolean hasNext() {
    return fIndex <= fArray.length - 1;
  }

  @Override
  public Integer next() throws NoSuchElementException {
    if (hasNext()) {
      Integer next = fArray[fIndex];
      fIndex++;
      return next;
    } else {
      throw new NoSuchElementException("No more element");
    }
  }

  public static void main(String[] args) {
    int[] a = {1,2,3,4,5};
    IntArrayIterator iter = new IntArrayIterator(a);
    int Sum = 0;

    while (iter.hasNext()) {
      Sum += iter.next(); // auto-unboxing: Integer -> int
    }

    System.out.println("Iterator sum of " + Arrays.toString(a) + " is: " + Sum);
  }
}
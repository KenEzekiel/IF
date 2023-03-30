/**
 * Animal.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public abstract class Animal implements Comparable<Animal> {
  public int compareTo(Animal a) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    if (this.getAnimalPower() > a.getAnimalPower()) {
      return 1;
    } 
    if (this.getAnimalPower() < a.getAnimalPower()) {
      return -1;
    }
    return 0;
  }

  protected int numberOfLegs;
  protected int children = 0;

  public Animal(int numberOfLegs) {
    this.numberOfLegs = numberOfLegs;
    this.children = children;
  }

  
  public int getNumberOfLegs() { return numberOfLegs; }
  public int getNumberOfChildren() { return children; }

  public void increaseChild(int inc) { this.children += inc; }

  public abstract int getAnimalPower();

  public static void main(String[] args) {
    
  }

}

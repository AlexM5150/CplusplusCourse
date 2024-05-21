import java.time.*;
import java.time.temporal.*;
public class test {
   public static void main(String[] args) {
      LocalTime lt1 = LocalTime.parse("12:15:30");
      LocalTime lt2 = LocalTime.parse("12:21:30");
      System.out.println("The first LocalTime is: " + lt1);
      System.out.println("The second LocalTime is: " + lt2);
      System.out.println("\nThe difference between two LocalTimes in hours is: " + lt1.until(lt2, ChronoUnit.MINUTES));
   }
}
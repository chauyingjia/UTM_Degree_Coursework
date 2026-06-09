package lab1;

public class Hospital {
    public static void main(String[] args){

        //create two patient objects with initial values
        Patient patient1 = new Patient("Ali", "P001", 120.50);
        Patient patient2 = new Patient("Siti", "P002", 80.00);

        //print both patients' details
        System.out.println("\nOriginal Details: ");
        System.out.println(patient1.toString());
        System.out.println(patient2.toString());
    
        //update payment of the first patient
        patient1.updatePayment(150.00);

        //copy payment from the first patient to the second
        patient2.copyPaymentFrom(patient1);

        //print updated details
        System.out.println("\nAfter Changes: ");
        System.out.println(patient1.toString());
        System.out.println(patient2.toString());
    }
    
}

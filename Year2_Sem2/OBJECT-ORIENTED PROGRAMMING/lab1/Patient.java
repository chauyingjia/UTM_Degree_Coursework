package lab1;

public class Patient {
    private String name;
    private String id;
    private double paymentAmount;

    // Constructor to initialize patient details
    public Patient(String name, String id, double paymentAmount) {
        this.name = name;
        this.id = id;
        this.paymentAmount = paymentAmount;
    }

    // Method to update the patient's payment
    public void updatePayment(double newAmount) {
        this.paymentAmount = newAmount;
    }

    // Method to copy payment from another patient
    public void copyPaymentFrom(Patient otherPatient) {
        this.paymentAmount = otherPatient.paymentAmount;
    }

    // Overriding toString() to display patient information
    @Override
    public String toString() {
        return "Patient ID: " + id + ", Name: " + name + ", Payment: RM " + paymentAmount;
    }
}

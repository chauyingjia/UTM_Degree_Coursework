// Hotel.java
// TEST 2 – Question 1
// SECJ2154 – 2023/2024-2
// Name: ???
// Matric No.: ???

import java.util.ArrayList;
class Customer {
    private String name;
    private int id;

    public Customer(String name, int id) { 
        this.name = name;
        this.id = id;
    }

    public int getId() {
       return id;
    }

    @Override
    public String toString() {
        return "Customer{name: " + name + ", id: " + id + "}";  
    }
}

class Room {
    private int roomNumber;
    private String type;

    public Room(int roomNumber, String type) {
        this.roomNumber = roomNumber;
        this.type = type;
    }

    @Override
    public String toString() {
        return "Room{roomNumber: " + roomNumber + ", type: " + type + "}";  
    }
}

public class Hotel {
    private ArrayList<Customer> customers; 
    private ArrayList<Room> rooms;  

    public Hotel() {
        customers = new ArrayList<>();  
        rooms = new ArrayList<>(); 
    }

    public void addCustomer(Customer customer) {
        customers.add(customer); 
    }

    public void removeCustomer(int id) {
        for (int i = 0; i < customers.size(); i++) {
            Customer customer = customers.get(i);  
            if (customer.getId() == id) { 
                customers.remove(customer); 
                break;
            }
        }
    }

    public void addRoom(Room room) {
        rooms.add(room);  
    }

    public void displayCustomers() {
        for (Customer cust : customers) {  
            System.out.println(cust); 
        }
    }

    public void displayRooms() {
        for (Room room : rooms) {  
            System.out.println(room);
        }
    }

    public static void main(String[] args) {
        Hotel hotel = new Hotel();
        hotel.addCustomer(new Customer("Aliza", 101));
        hotel.addCustomer(new Customer("Hafiz", 102));
        hotel.addRoom(new Room(201, "Single"));
        hotel.addRoom(new Room(202, "Double"));
        hotel.displayCustomers();
        hotel.displayRooms(); 
        hotel.removeCustomer(101); 
        System.out.println("After removal:");
        hotel.displayCustomers();
    }
}

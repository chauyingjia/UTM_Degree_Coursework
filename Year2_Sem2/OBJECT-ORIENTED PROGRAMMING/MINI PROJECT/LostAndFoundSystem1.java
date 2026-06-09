// LostAndFoundSystem.java - simplified starter version

import java.io.*;
import java.time.LocalDate;
import java.util.*;

// Enum for item status
enum ItemStatus {
    LOST, FOUND, RETURNED
}

// Abstract class User
abstract class User {
    protected String userId, name, password;

    public User(String userId, String name, String password) {
        this.userId = userId;
        this.name = name;
        this.password = password;
    }

    public boolean login(String userId, String password) {
        return this.userId.equals(userId) && this.password.equals(password);
    }

    public void logout() {
        System.out.println(name + " has logged out.");
    }

    public abstract String getRole();
}

// Interface
interface Reportable {
    void reportLostItem(Item item);
    void reportFoundItem(Item item);
}

// Student class
class Student extends User implements Reportable {
    private ArrayList<Item> reportedItems = new ArrayList<>();
    private static final String REPORT_FILE = "stuReportFile.txt";

    public Student(String userId, String name, String password) {
        super(userId, name, password);
    }

    public String getRole() {
        return "Student";
    }

    public void reportLostItem(Item item) {
        item.setStatus(ItemStatus.LOST);
        item.setReportedBy(this);
        reportedItems.add(item);
        saveReportToFile(item);
        System.out.println("Lost item reported: " + item.getItemName());
    }

    public void reportFoundItem(Item item) {
        item.setStatus(ItemStatus.FOUND);
        item.setReportedBy(this);
        reportedItems.add(item);
        saveReportToFile(item);
        System.out.println("Found item reported: " + item.getItemName());
    }

    private void saveReportToFile(Item item) {
        File file = new File(REPORT_FILE);
        boolean fileExists = file.exists();
        boolean isEmpty = file.length() == 0;

        try (PrintWriter writer = new PrintWriter(new FileWriter(file, true))) {
            // Write header only if file is new or empty
            if (!fileExists || isEmpty) {
                writer.println(String.format("%-8s %-12s %-10s %-12s %s", "ItemID", "Name", "Status", "ReportedBy", "Description"));
                writer.println("--------------------------------------------------------------------------");
            }

            // Write item row
            String formatted = String.format("%-8s %-12s %-10s %-12s %s",
                    item.getItemId(), item.getItemName(), item.getStatus(), name, item.getDescription());
            writer.println(formatted);
        } catch (IOException e) {
            System.out.println("Error writing report: " + e.getMessage());
        }
    }

    public void viewReports() {
        try (BufferedReader reader = new BufferedReader(new FileReader(REPORT_FILE))) {
            String line;
            System.out.println("\n--- All Reported Lost & Found Items ---\n");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error reading report file: " + e.getMessage());
        }
    }
}

// Admin class
class Admin extends User {
    private static final String REPORT_FILE = "stuReportFile.txt";

    public Admin(String userId, String name, String password) {
        super(userId, name, password);
    }

    public String getRole() {
        return "Admin";
    }

    public void updateItemStatus(int itemId, ItemStatus newStatus) {
        ArrayList<String> fileLines = new ArrayList<>();
        boolean itemFound = false;

        // Read and update the file content
        try (BufferedReader reader = new BufferedReader(new FileReader(REPORT_FILE))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Skip the header row and separator line
                if (line.startsWith("ItemID") || line.startsWith("----") || line.trim().isEmpty()) {
                    fileLines.add(line); 
                    continue;
                }

                // Split using regex for fixed-width format
                String[] parts = line.trim().split("\\s{2,}"); 

                if (parts.length >= 4) {
                    int currentId = Integer.parseInt(parts[0]);
                    if (currentId == itemId) {
                        // Rebuild the line with updated status
                        String updatedLine = String.format("%-8s %-12s %-10s %-12s %s",
                                parts[0], parts[1], newStatus, parts[3], parts.length >= 5 ? parts[4] : "");
                        fileLines.add(updatedLine);
                        itemFound = true;
                        System.out.println("Item status updated: " + parts[1] + " -> " + newStatus);
                        continue;
                    }
                }

                fileLines.add(line);
            }
        } catch (IOException | NumberFormatException e) {
            System.out.println("Error reading file: " + e.getMessage());
            return;
        }

        if (!itemFound) {
            System.out.println("Item with ID " + itemId + " not found.");
            return;
        }

        // Write back to file
        try (PrintWriter writer = new PrintWriter(new FileWriter(REPORT_FILE))) {
            for (String updatedLine : fileLines) {
                writer.println(updatedLine);
            }
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    public void viewAllReports() {
        try (BufferedReader reader = new BufferedReader(new FileReader(REPORT_FILE))) {
            String line;
            System.out.println("\n--- All Lost & Found Items ---\n");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}

// Item class
class Item {
    private int itemId;
    private String itemName, description;
    private LocalDate reportDate;
    private ItemStatus status;
    private Student reportedBy;

    public Item(int itemId, String itemName, String description) {
        this.itemId = itemId;
        this.itemName = itemName;
        this.description = description;
        this.reportDate = LocalDate.now();
    }

    public void displayItemInfo() {
        System.out.println("[" + itemId + "] " + itemName + " - " + status);
        System.out.println("  Description: " + description);
        System.out.println("  Reported on: " + reportDate);
        if (reportedBy != null)
            System.out.println("  Reported by: " + reportedBy.name);
    }

    public void setStatus(ItemStatus status) {
        this.status = status;
    }

    public void setReportedBy(Student s) {
        this.reportedBy = s;
    }

    public String getItemName() {
        return itemName;
    }

    public int getItemId() {
        return itemId;
    }

    public ItemStatus getStatus() {
        return status;
    }

    public String getDescription() {
        return description;
    }

}

// Manager class for logic and file operations
class LostAndFoundManager {
    private ArrayList<Item> allItems = new ArrayList<>();

    public void addItem(Item item) {
        allItems.add(item);
    }

    public void saveItemsToFile(String reportFile) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(reportFile))) {
            for (Item item : allItems) {
                writer.println(item.getItemId() + ", " + item.getItemName() + ", " + item.getStatus());
            }
        } catch (IOException e) {
            System.out.println("Error saving items: " + e.getMessage());
        }
    }

    public int loadItemsFromFile(String reportFile) {
        int lastId = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(reportFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Skip header or separator lines
                if (line.trim().isEmpty() || line.startsWith("ItemID") || line.startsWith("-")) {
                    continue;
                }

                // Split by two or more spaces
                String[] parts = line.trim().split("\\s{2,}");
                if (parts.length >= 4) {
                    int id = Integer.parseInt(parts[0].trim());
                    String name = parts[1].trim();
                    String status = parts[2].trim();
                    String desc = parts.length >= 5 ? parts[4].trim() : "";

                    Item item = new Item(id, name, desc);
                    item.setStatus(ItemStatus.valueOf(status));
                    allItems.add(item);

                    // track highest ID
                    if (id > lastId) {
                        lastId = id; 
                    }
                }
            }
        } catch (IOException | NumberFormatException e) {
            System.out.println("Error loading items: " + e.getMessage());
        }

        return lastId;
    }


    public Item searchItemById(int id) {
        for (Item item : allItems) {
            if (item.getItemId() == id) {
                return item;
            }
        }
        return null;
    }

    public ArrayList<Item> getItemsByStatus(ItemStatus status) {
        ArrayList<Item> result = new ArrayList<>();
        for (Item item : allItems) {
            if (item.getStatus() == status) {
                result.add(item);
            }
        }
        return result;
    }

    public ArrayList<Item> getAllItems() {
        return allItems;
    }
}

// Main class (for testing)
public class LostAndFoundSystem {
    public static void main(String[] args) {
        // Initialize item manager and load from file
        LostAndFoundManager manager = new LostAndFoundManager();
        int lastUsedId = manager.loadItemsFromFile("stuReportFile.txt");
        int itemCounter = lastUsedId + 1;

        Map<String, User> users = new HashMap<>();
        users.put("S001", new Student("S001", "Ali", "1234"));
        users.put("A001", new Admin("A001", "Admin", "adminpass"));

        // Login process
        Scanner scanner = new Scanner(System.in);
        User loggedInUser = null;

        System.out.print("Please enter your ID: ");
        String userId = scanner.nextLine().trim();
        System.out.print("Please enter your password: ");
        String password = scanner.nextLine().trim();

        // Check if user exists and credentials match
        if (users.containsKey(userId)) {
            User user = users.get(userId);
            if (user.login(userId, password)) {
                loggedInUser = user;
                System.out.println("Login successful! Welcome " + user.name + " (" + user.getRole() + ")");
            } else {
                System.out.println("Invalid ID or password.");
            }
        } else {
            System.out.println("User ID not found.");
        }

        // Check if login was successful before proceeding
        if (loggedInUser == null) {
            System.out.println("Login failed. Exiting...");
            return;
        }

        if (loggedInUser instanceof Student) {
            Student student = (Student) loggedInUser;
            Scanner studentInput = new Scanner(System.in);

            while (true) {
                System.out.println("\n1. Report Lost Item");
                System.out.println("2. Report Found Item");
                System.out.println("3. View All Reports");
                System.out.println("4. Logout");
                System.out.print("Choose an option: ");

                int choice = studentInput.nextInt();
                studentInput.nextLine(); // consume newline

                switch (choice) {
                    case 1:
                        int lostItemId = itemCounter++;
                        System.out.print("Enter item name: ");
                        String lostItemName = studentInput.nextLine();
                        System.out.print("Enter item description: ");
                        String lostItemDesc = studentInput.nextLine();

                        Item lostItem = new Item(lostItemId, lostItemName, lostItemDesc);
                        student.reportLostItem(lostItem);
                        break;

                    case 2:
                        int foundItemId = itemCounter++;
                        System.out.print("Enter item name: ");
                        String foundItemName = studentInput.nextLine();
                        System.out.print("Enter item description: ");
                        String foundItemDesc = studentInput.nextLine();

                        Item foundItem = new Item(foundItemId, foundItemName, foundItemDesc);
                        student.reportFoundItem(foundItem);
                        break;

                    case 3:
                        student.viewReports();
                        break;

                    case 4:
                        student.logout();
                        return;

                    default:
                        System.out.println("Invalid option");
                }
            }
        } else if (loggedInUser instanceof Admin) {
            Admin admin = (Admin) loggedInUser;
            Scanner adminInput = new Scanner(System.in);

            while (true) {
                System.out.println("\n1. View all items");
                System.out.println("2. Update item status");
                System.out.println("3. Logout");
                System.out.print("Choose an option: ");

                int choice = adminInput.nextInt();
                adminInput.nextLine(); // consume newline

                switch (choice) {
                    case 1:
                        admin.viewAllReports();
                        break;
                        
                    case 2:
                        System.out.print("Enter item ID to update: ");
                        int itemId = adminInput.nextInt();
                        adminInput.nextLine();
                        System.out.println("Enter new status (LOST/FOUND/RETURNED): ");
                        String input = adminInput.nextLine();
                        String status = input.toUpperCase();
                        admin.updateItemStatus(itemId, ItemStatus.valueOf(status));
                        break;
                        
                    case 3:
                        admin.logout();
                        return;
                        
                    default:
                        System.out.println("Invalid option");
                }
            }
        }

        // Logout
        loggedInUser.logout();
    }
}
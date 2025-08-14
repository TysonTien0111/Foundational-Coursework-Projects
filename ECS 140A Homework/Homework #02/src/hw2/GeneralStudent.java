package hw2;

public abstract class GeneralStudent {
    private final int studentID;

    private String firstName;
    private String lastName;
    private int age;
    private int numOfCredits;

    public GeneralStudent(int studentID, String firstName, String lastName, int age, int numOfCredits) {
        this.studentID = studentID;
        setFirstName(firstName);
        setLastName(lastName);
        setAge(age);
        setNumOfCredits(numOfCredits);
    }

    public void printData() {
        System.out.println("ID number: " + getStudentID());
        System.out.println("Name: " + getFirstName() + " " + getLastName());
        System.out.println("Age: " + getAge());
    }

    public abstract double computeFees();

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setNumOfCredits(int numOfCredits) {
        this.numOfCredits = numOfCredits;
    }

    public int getStudentID() {
        return studentID;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getAge() {
        return age;
    }

    public int getNumOfCredits() {
        return numOfCredits;
    }
}

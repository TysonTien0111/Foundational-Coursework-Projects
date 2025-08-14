package hw2;

public class CertificateStudent extends NonDegreeSeeking {
    final private double fixedFee = 700.0;
    final private double costPerCredit = 300.0;

    private char typeOfCertificate;

    public CertificateStudent(int studentID, String firstName, String lastName, int age, int numOfCredits,
            char typeOfCertificate) {
        super(studentID, firstName, lastName, age, numOfCredits);

        setTypeOfCertificate(typeOfCertificate);
    }

    @Override
    public void printData() {
        super.printData();

        System.out.println(
                getFirstName() + " is a non-degree-seeking, certificate student enrolled in " + getNumOfCredits()
                        + " credits");

        String fullTypeOfCertificate = "";

        switch (typeOfCertificate) {
            case 'S':
                fullTypeOfCertificate = "gaming science";
                break;

            case 'M':
                fullTypeOfCertificate = "hotel management";
                break;

            case 'A':
                fullTypeOfCertificate = "lounge arts";
                break;

            case 'E':
                fullTypeOfCertificate = "beverage engineering";
                break;

            default:
                break;
        }

        System.out.println(getFirstName() + "'s certificate is " + fullTypeOfCertificate);
    }

    @Override
    public double computeFees() {
        double payment = fixedFee + (getNumOfCredits() * costPerCredit);

        return payment;
    }

    public void setTypeOfCertificate(char typeOfCertificate) {
        this.typeOfCertificate = typeOfCertificate;
    }

    public char getTypeOfCertificate() {
        return typeOfCertificate;
    }
}

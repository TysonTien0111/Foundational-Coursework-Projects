package hw2;

public class DegreeSeeking extends GeneralStudent {
    final private double recreationAndAtheleticFee = 100.0;
    final private double studentUnionFee = 50.0;
    final private double creditPerHour = 275.0;
    final private int maxCreditsEnrolled = 12;
    final private double noRefund = 0.0;
    final private double zero = 0.0;

    private char major;
    private char academicStanding;
    private double financialAid;

    public DegreeSeeking(int studentID, String firstName, String lastName, int age, int numOfCredits, char major,
            char academicStanding, double financialAid) {
        super(studentID, firstName, lastName, age, numOfCredits);

        setMajor(major);
        setAcademicStanding(academicStanding);
        setFinancialAid(financialAid);
    }

    @Override
    public void printData() {
        super.printData();

        System.out
                .println(getFirstName() + " is a degree-seeking student enrolled in " + getNumOfCredits() + " credits");

        if (financialAid > zero) {
            System.out
                    .println(getFirstName() + " receives $" + getFinancialAid() + " in financial assistance per term");
        } else {
            System.out.println(getFirstName() + " receives no financial assistance per term");
        }

        String fullMajor = "";

        switch (major) {
            case 'S':
                fullMajor = "gaming science";
                break;

            case 'M':
                fullMajor = "hotel management";
                break;

            case 'A':
                fullMajor = "lounge arts";
                break;

            case 'E':
                fullMajor = "beverage engineering";
                break;

            default:
                break;
        }

        System.out.println(getFirstName() + "'s major is " + fullMajor);

        String fullAcademicStanding = "";

        switch (academicStanding) {
            case 'G':
                fullAcademicStanding = "good";
                break;

            case 'W':
                fullAcademicStanding = "concerning";
                break;

            case 'P':
                fullAcademicStanding = "bad";
                break;

            default:
                break;
        }

        System.out.println(getFirstName() + "'s academic standing is " + fullAcademicStanding);
    }

    @Override
    public double computeFees() {
        double perHourCreditsFee = creditPerHour * getNumOfCredits();
        double maxCreditsFee = creditPerHour * maxCreditsEnrolled;

        double totalFee = recreationAndAtheleticFee + studentUnionFee;
        double payment = (getNumOfCredits() > maxCreditsEnrolled) ? (totalFee + maxCreditsFee)
                : (totalFee + perHourCreditsFee);
        double finalFee = payment - financialAid;

        return ((finalFee) > 0) ? finalFee : noRefund;
    }

    public void setMajor(char major) {
        this.major = major;
    }

    public void setAcademicStanding(char academicStanding) {
        this.academicStanding = academicStanding;
    }

    public void setFinancialAid(double financialAid) {
        this.financialAid = financialAid;
    }

    public char getMajor() {
        return major;
    }

    public char getAcademicStanding() {
        return academicStanding;
    }

    public double getFinancialAid() {
        return financialAid;
    }
}

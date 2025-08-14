package hw2;

public class SeniorCitizen extends NonDegreeSeeking {
    final private double fixedFee = 100.0;
    final private double extraCreditCostPerHour = 50.0;
    final private int minNumOfCredits = 6;

    public SeniorCitizen(int studentID, String firstName, String lastName, int age, int numOfCredits) {
        super(studentID, firstName, lastName, age, numOfCredits);
    }

    @Override
    public void printData() {
        super.printData();

        System.out.println(getFirstName() + " is a non-degree-seeking, senior citizen enrolled in " + getNumOfCredits()
                + " credits");
    }

    @Override
    public double computeFees() {
        double extraHoursFee = extraCreditCostPerHour * (getNumOfCredits() - minNumOfCredits);
        double payment = (getNumOfCredits() > 6) ? (fixedFee + extraHoursFee) : fixedFee;

        return payment;
    }
}

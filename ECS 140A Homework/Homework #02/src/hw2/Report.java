package hw2;

import java.io.File;
import java.util.Scanner;

// TODO: Make sure you create a package named hw2 and add the package name to every Java file 

import java.util.Scanner;

/*
 * To ensure you get graded correctly by autograder, 
 * DO NOT change the file name (Report.java), method name (generateReport), or add parameters to this method.
 * Fill in your code where there is a TODO comment.
 * Use the provided variables in the reportBuilder code. 
 * Check if your generateReport() output is equal to hw2_output.txt (String.equals())
 * 
 * Questions or comments? Direct them to the TA. 
 * 
 */
public class Report {
    final static private char degreeSeeking = 'Y';

    // generateReport() should be a public static method that takes no parameters
    // and returns a String
    public static String generateReport() {
        StringBuilder reportBuilder = new StringBuilder();
        // TODO:
        // Read hw2.txt line by line
        // Hardcode "hw2.txt" as your input, which means that you should put hw2.txt
        // right under your Eclipse workspace folder (the top level of the workspace
        // hierarchy).

        // For each record, create an instance from the corresponding class (FinAssist,
        // NoFinAssist, Degree, etc.)

        // Save all instances to a GeneralStudent[] array. GeneralStudent is the
        // interface or parent
        // class for all the
        // classes you make.

        GeneralStudent[] students = new GeneralStudent[100]; // save all the student record objects here

        int index = 0;

        try {
            File hw2 = new File("hw2.txt");
            Scanner hw2Reader = new Scanner(hw2);

            while (hw2Reader.hasNextLine()) {
                String studentInformation = hw2Reader.nextLine();
                String[] parsedStudentInfo = studentInformation.split(";");

                int studentID = Integer.parseInt(parsedStudentInfo[0]);
                String firstName = parsedStudentInfo[1];
                String lastName = parsedStudentInfo[2];
                int age = Integer.parseInt(parsedStudentInfo[3]);
                int numOfCredits = Integer.parseInt(parsedStudentInfo[4]);

                char degreeStatus = parsedStudentInfo[5].charAt(0);

                switch (degreeStatus) {
                    case (degreeSeeking):
                        char major = parsedStudentInfo[6].charAt(0);
                        char academicStanding = parsedStudentInfo[7].charAt(0);
                        char financialAidStatus = parsedStudentInfo[8].charAt(0);
                        double financialAid = (financialAidStatus == 'Y') ? Double.parseDouble(parsedStudentInfo[9])
                                : 0.0;

                        DegreeSeeking degreeSeekingStudent = new DegreeSeeking(studentID, firstName, lastName, age,
                                numOfCredits, major, academicStanding, financialAid);
                        students[index] = degreeSeekingStudent;
                        index++;
                        break;

                    default:
                        char certificateStatus = parsedStudentInfo[6].charAt(0);

                        if (certificateStatus == 'C') {
                            char typeOfCertificate = parsedStudentInfo[7].charAt(0);
                            CertificateStudent certificateStudent = new CertificateStudent(studentID, firstName,
                                    lastName, age, numOfCredits, typeOfCertificate);
                            students[index] = certificateStudent;
                            index++;
                        } else {
                            SeniorCitizen seniorCitizen = new SeniorCitizen(studentID, firstName, lastName, age,
                                    numOfCredits);
                            students[index] = seniorCitizen;
                            index++;
                        }
                        break;
                }
            }
            hw2Reader.close();
        } catch (Exception k) {
        }

        // variables.
        // INDIVIDUAL REPORTS, listing of all students and the fees they have each been
        // assessed

        // Print out first and last name and fee amount
        reportBuilder.append("Summary of each student's fees assessed: \n\n");
        // TODO: iterate over all GeneralStudent records and compute the individual
        // student_fee. Assign student_name.

        // SUMMARY REPORT of fees assessed for each of the four types of student
        int degree_nofin_fees = 0;
        int degree_fin_fees = 0;
        int certificate_fees = 0;
        int senior_fees = 0;
        int total_fees = 0;

        for (int i = 0; i < index; i++) {
            int student_fee = (int) students[i].computeFees(); // TODO: Change this! Assign its value in the iteration
                                                               // below
            // and
            // use the
            // provided print statement
            String student_name = students[i].getFirstName() + " " + students[i].getLastName(); // TODO: Change
            // this!
            // Assign its value in
            // the iteration below
            // and use the
            // provided print statement
            // TODO: put the following line in your for/while loop so that every student's
            // fee gets printed
            reportBuilder.append(student_name + " has $" + String.format("%,d", student_fee) + " fees assessed \n");

            if (students[i] instanceof DegreeSeeking) {
                DegreeSeeking actualDegreeSeekingStudent = (DegreeSeeking) students[i];

                if (actualDegreeSeekingStudent.getFinancialAid() > 0.0) {
                    degree_fin_fees += student_fee;
                } else {
                    degree_nofin_fees += student_fee;
                }
            } else if (students[i] instanceof CertificateStudent) {
                certificate_fees += student_fee;
            } else {
                senior_fees += student_fee;
            }
        }

        // This should work once your GeneralStudent classes are implemented
        // Don't worry about the string formatting in printData() :)
        // Make sure you do not comment out the following two lines when you submit the
        // hw
        students[0].printData();
        students[1].printData();

        // TODO: Calculate the fees by iterating through all students, or do it in the
        // loop above

        total_fees = senior_fees + certificate_fees + degree_fin_fees + degree_nofin_fees;

        // Print out the total fees for different students
        reportBuilder.append("\n\n");
        reportBuilder.append("Summary of all student fees assessed: \n\n");
        reportBuilder.append(
                "Degree-seeking students without financial assistance: $" + String.format("%,d", degree_nofin_fees)
                        + "\n");
        reportBuilder
                .append("Degree-seeking students with financial assistance: $" + String.format("%,d", degree_fin_fees)
                        + "\n");
        reportBuilder.append("Certificate students: $" + String.format("%,d", certificate_fees) + "\n");
        reportBuilder.append("Senior citizens: $" + String.format("%,d", senior_fees) + "\n\n");
        reportBuilder.append("Total fees assessed: $" + String.format("%,d", total_fees));

        return reportBuilder.toString();
    }

    public static void main(String[] args) {
        // You may test your Report here by comparing the output with the provided
        // hw2_output.txt
        System.out.println(generateReport());
    }
}

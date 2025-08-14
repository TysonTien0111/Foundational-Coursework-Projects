module lab4_tb;

  // Inputs
  reg clk;
  reg a;
  reg b;

  // Output
  wire unlock;

  // Instantiate the Unit Under Test (UUT)
  
lab4s25  uut (
    .clk(clk),
    .a(a),
    .b(b),
    .unlock(unlock)
  );

  // Clock generation: 10ns period
  always #5 clk = ~clk;

  // Test sequence
  initial begin
    // Initialize inputs
    clk = 0;
    a = 0;
    b = 0;

    // Hold reset-like idle state for a bit
    #20

    $display("Starting Test 1: Correct unlock sequence...");

    // Cycle 1: a = 1, b = 0
    a = 1; b = 0; #10;
    a = 0; b = 0; #10;

    // Cycle 2: a = 0, b = 1
    a = 0; b = 1; #10;
    a = 0; b = 0; #10;

    // Cycle 3: a = 1, b = 0
    a = 1; b = 0; #10;
    a = 0; b = 0; #10;

    // Cycle 4: a = 1, b = 0 -> unlock expected
    a = 1; b = 0; #10;

    if (unlock !== 1) begin
      $error("FAILED: Unlock should be HIGH after correct sequence.");
    end else begin
      $display("PASSED: Unlock correctly asserted.");
    end

    // Wait in unlocked state
    a = 0; b = 0; #10;

    // Trigger reset by setting any input high
    a = 1; b = 0; #10;

    if (unlock !== 0) begin
      $error("FAILED: Unlock should be LOW after input high post-unlock.");
    end else begin
      $display("PASSED: Unlock correctly de-asserted.");
    end

    // Additional test: incorrect sequence
    $display("Starting Test 2: Incorrect sequence...");

    a = 1; b = 0; #10;
    a = 0; b = 1; #10;  // Skipping the required 00 cycle here!
    a = 1; b = 0; #10;
    a = 0; b = 0; #10;
    a = 1; b = 0; #10;

    if (unlock !== 0) begin
      $error("FAILED: Unlock should remain LOW for incorrect sequence.");
    end else begin
      $display("PASSED: Unlock correctly stayed LOW for bad sequence.");
    end

    $display("All tests completed.");
    $finish;
  end

endmodule

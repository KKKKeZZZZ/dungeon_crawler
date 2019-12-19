#ifndef TESTING_H
#define TESTING_H
#include <iostream>
#include <sstream>
#include <memory>

/*
 * NOTE: You MAY EDIT this file to perform testing as you progress through the assignment.
 * Be sure to edit the implementation in testing.cpp as well.
 */

/**
 * @brief The Testing class is a simple example of performing unit tests.
 * You can modify as required to support the testing of your assignment.
 *
 * Tests should cover correct operation of your classes including (but not
 * limited to): constructors, destructors, accessors, mutators, and public members.
 *
 * An incomplete example has been provided for you.
 */
class Testing
{
public:
  Testing();
  ~Testing();

  /**
   * @brief runTests the entry point for running one or more tests.
   */
  void runTests();

  /**
   * @brief printFailures outputs the collected failure messages to the given stream
   * @param ostream
   */
  void printFailures(std::ostream &ostream);

private:
  bool _failure; ///< boolean indicating failure state of current test
  std::stringstream _failMessages; ///< stream to collect failure messages during testing

  // Example test function for the Character class
  std::string testCharacter();
  std::string testCreature();
  std::string testDoor();
  std::string testDungeon();
  std::string testGame();
  std::string testItem();
  std::string testRoom();
  std::string testWall();

  // TODO: add functions for your own tests here


  /* ------------------------------------------------------------------------------
   * NOTE: DO NOT MODIFY the following 'test' functions.
   * The following are helper functions that operate a little like common
   * Unit Testing frameworks. You do not need to understand their implementations,
   * but hopefully you will by the end of the course.
   * -----------------------------------------------------------------------------*/

  /**
   * @brief equals Test support function, compares the expected and actual values, if they
   * are not equal to one another, puts the Testing object into the failure
   * state and appends failMessage to the output to be reported later.
   *
   * @param expected the expected value
   * @param actual the actual value
   * @param failMessage the message to display if the test fails
   */
  template<class T>
  void equal(const T &expected, const T &actual, const std::string &failMessage) {
    if (expected != actual) {
      _failure = true;
      _failMessages << failMessage << " [expected: " << expected << " actual: " << actual  << "]" << std::endl;
    }
  }

  /**
   * @brief equals Test support function, compares the expected and actual values, if they
   * are equal to one another, puts the Testing object into the failure
   * state and appends failMessage to the output to be reported later.
   *
   * @param expected the expected value
   * @param actual the actual value
   * @param failMessage the message to display if the test fails
   */
  template<class T>
  void notEqual(const T &expected, const T &actual, const std::string &failMessage) {
    if (expected == actual) {
      _failure = true;
      _failMessages << failMessage << " [value: " << expected << "]" << std::endl;
    }
  }

  /**
   * @brief lessThan Test support function, compares the expected and actual values,
   * if they actual is greater than or equal to expected, puts the Testing object into the failure
   * state and appends failMessage to the output to be reported later.
   *
   * @param expected the expected value
   * @param actual the actual value
   * @param failMessage the message to display if the test fails
   */
  template<class T>
  void lessThan(const T &expected, const T &actual, const std::string &failMessage) {
    if (actual >= expected) {
      _failure = true;
      _failMessages << failMessage << " [expected less than: " << expected << " actual: " << actual  << "]" << std::endl;
    }
  }

  /**
   * @brief greaterThan Test support function, compares the expected and actual values,
   * if they actual is less than or equal to expected, puts the Testing object into the failure
   * state and appends failMessage to the output to be reported later.
   *
   * @param expected the expected value
   * @param actual the actual value
   * @param failMessage the message to display if the test fails
   */
  template<class T>
  void greaterThan(const T &expected, const T &actual, const std::string &failMessage) {
    if (actual <= expected) {
      _failure = true;
      _failMessages << failMessage << " [expected greater than: " << expected << " actual: " << actual  << "]" << std::endl;
    }
  }

  /**
   * @brief instanceOf Test support function, checks if the value of the given pointer
   * is of the template type T. If not, the Testing object is put into the fail state
   * and the failure message is appended.
   *
   * @param value the shared pointer to check the type
   * @param failMessage
   */
  template<class T, class U>
  void instanceOf(const std::shared_ptr<U> &value, const std::string &failMessage) {
    if (!std::dynamic_pointer_cast<T>(value)) {
      _failure = true;
      _failMessages << failMessage << std::endl;
    }
  }

  /**
   * @brief passFailText convenience function to return the "Passed" or "Failed" strings.
   * @return "Pass" or "Fail"
   */
  inline std::string passFailText() {
    bool failed = _failure;
    _failure = false; // reset state for next test
    return failed ? "Failed" : "Passed";
  }

};

#endif // TESTING_H

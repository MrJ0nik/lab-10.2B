#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestGetProfileGrade)
        {
            Student student1 = { "Ivanov", 1, COMPUTER_SCIENCE, 90, 80, 85 };
            Student student2 = { "Petrov", 2, INFORMATICS, 75, 85, 90 };
            Student student3 = { "Sidorov", 3, LABOR_EDUCATION, 70, 90, 95 };

            Assert::AreEqual(85, GetProfileGrade(student1));
            Assert::AreEqual(90, GetProfileGrade(student2));
            Assert::AreEqual(95, GetProfileGrade(student3));
        }

        TEST_METHOD(TestPhysicalSort)
        {
            Student students[3] = {
                { "Ivanov", 2, COMPUTER_SCIENCE, 90, 80, 85 },
                { "Petrov", 1, INFORMATICS, 75, 85, 90 },
                { "Sidorov", 3, LABOR_EDUCATION, 70, 90, 95 }
            };

            PhysicalSort(students, 3);

            Assert::AreEqual(std::string("Sidorov"), students[0].surname);
            Assert::AreEqual(std::string("Petrov"), students[1].surname);
            Assert::AreEqual(std::string("Ivanov"), students[2].surname);
        }

        TEST_METHOD(TestIndexSort)
        {
            Student students[3] = {
                { "Ivanov", 2, COMPUTER_SCIENCE, 90, 80, 85 },
                { "Petrov", 1, INFORMATICS, 75, 85, 90 },
                { "Sidorov", 3, LABOR_EDUCATION, 70, 90, 95 }
            };
            int indexArray[3] = { 0, 1, 2 };

            IndexSort(students, 3, indexArray);

            Assert::AreEqual(std::string("Sidorov"), students[indexArray[0]].surname);
            Assert::AreEqual(std::string("Petrov"), students[indexArray[1]].surname);
            Assert::AreEqual(std::string("Ivanov"), students[indexArray[2]].surname);
        }

        TEST_METHOD(TestBinarySearch)
        {
            Student students[3] = {
                { "Ivanov", 2, COMPUTER_SCIENCE, 90, 80, 85 },
                { "Petrov", 1, INFORMATICS, 75, 85, 90 },
                { "Sidorov", 3, LABOR_EDUCATION, 70, 90, 95 }
            };
            int indexArray[3] = { 0, 1, 2 };
            IndexSort(students, 3, indexArray);

            int result = BinarySearch(students, indexArray, 3, "Petrov", 1, 90);
            Assert::AreEqual(1, result);

            result = BinarySearch(students, indexArray, 3, "Ivanov", 2, 85);
            Assert::AreEqual(0, result);
        }
    };
}

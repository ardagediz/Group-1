"""
Please write your name
@author: Arda Gediz, sc23ag

"""

# Reminder: You are only allowed to import the csv module (done it for you).
# OTHER MODULES ARE NOT ALLOWED (NO OTHER IMPORT!!!).

import csv


class Diabetes:
    # Class for managing and analyzing a diabetes dataset
    def __init__(self, filepath) -> None:
        # Initialize the Diabetes class with data from a CSV file
        try:
            with open(filepath, 'r') as file:
                reader = csv.reader(file)
                self.header = next(reader)  # Store the header (first row csv)
                self.data = list(reader)  # Store the data (all other rows)
        except FileNotFoundError:
            raise FileNotFoundError(f"File not found: {filepath}")

    def get_dimension(self) -> list:
        # Return the dimensions of the data (rows, columns).
        row_count = len(self.data)  # Number of rows in the data
        column_count = len(self.data[0]) if self.data else 0
        return [row_count, column_count]

    def web_summary(self, filepath: str) -> None:
        # Counting Yes and No values for each attribute by classification
        summary = {}
        for row in self.data:
            classification = row[-1]  # The last column is the classification
            for i, value in enumerate(row[2:-1]):  # Skip Age, Gender, classifi
                attribute = self.header[i + 2]  # Adjust index for header
                if attribute not in summary:
                    summary[attribute] = {'Positive': {'Yes': 0, 'No': 0},
                                          'Negative': {'Yes': 0, 'No': 0}
                                          }
                summary[attribute][classification][value] += 1

        html_content = (
            '<html><head><title>Diabetes Data Summary</title></head>'
            '<body><h1>Diabetes Data Summary</h1>'
            '<table border="1"><tr><th>Attribute</th>'
            '<th>Classification</th><th>Yes</th><th>No</th></tr>'
        )

        # Add data rows to HTML content.
        for attribute, classifications in summary.items():
            for classification, counts in classifications.items():
                html_content += (
                    f'<tr><td>{attribute}</td><td>{classification}</td>'
                    f'<td>{counts["Yes"]}</td><td>{counts["No"]}</td></tr>'
                )

        html_content += '</table></body></html>'

        # Writing the HTML content to the file
        with open(filepath, 'w') as file:
            file.write(html_content)

    def count_instances(self, criteria) -> int:
        """
        Counts the number of instances in the data that meet the specified
        criteria.

        Parameters:
        criteria (dict): A dictionary where keys are column names and values
        arethe conditions to be met.The method will count the instances where
        all specified criteria are met.

        Returns:
        int: The count of instances meeting the criteria.

        Example:
        To count the instances for patients who are Male and have Itching:
        count = d1.count_instances(Gender="Male", Itching="Yes")

        To count the instances for patients who are 20 years old, Male, and
        have Obesity:
        count = d1.count_instances(Age="20", Gender="Male", Obesity="Yes")
        """

        count = 0
        for row in self.data:
            if all(row[self.header.index(key)] == value
                   for key, value in criteria.items()):
                count += 1
        return count


if __name__ == "__main__":
    # You can comment the following when you are testing your code
    # You can add more tests as you want

    # test diabetes_data.csv
    d1 = Diabetes("diabetes_data.csv")
    print(d1.get_dimension())
    d1.web_summary('stat01.html')
    # d1.count_instances() # change according to your criteria
    print()

    # test diabetes2_data.csv
    d2 = Diabetes("diabetes2_data.csv")
    print(d2.get_dimension())
    d2.web_summary('stat02.html')
    # d2.count_instances()  # change according to your criteria

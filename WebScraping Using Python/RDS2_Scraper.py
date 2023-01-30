import requests
from bs4 import BeautifulSoup

output_file = open('WebScraping Using Python/RDS2 Spring 2023 Offered Course List.txt', 'w')

url = 'https://rds2.northsouth.edu/index.php/common/showofferedcourses'

# getting the info from RDS 
r = requests.get(url)

soup = BeautifulSoup(r.text, 'html.parser')

# specifyng which table to get the data from 
course_detail = soup.find('table', class_='oferedtable table table-bordered table-striped table-hover')

for course in course_detail.find_all('thead'):
    result = course.find_all('th')
    data = ''
    for info in result:
        data += info.text + '\t'
        # print(info.text, end='    ')
    data += '\n'
    output_file.write(data)


for course in course_detail.find_all('tbody'):
    result = course.find_all('tr')
    for row in result:
        data = str(row.text.split())
        data += '\n'     
        output_file.write(data)

# print(course_detail)
output_file.close()
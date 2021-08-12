# Website Scraping using BeautifulSoup of Python
# Made by following up YouTube tutorial of freecodecamp.org
# Link : https://www.youtube.com/watch?v=XVv6mJpFOb0&ab_channel=freeCodeCamp.orgfreeCodeCamp.orgVerified
# RifatXia

from os import waitpid
from bs4 import BeautifulSoup

# Requests info from any website
import requests

import time

# Condition for filtering out the results using skill
print('Input the skill that you are unfamiliar with: ')
notSkills = input('>')
print(f'Filtering out {notSkills}')

# The default work function
def findJobs():

    # The variable to store the website URL and .text is used at the end to get the actual html in text format
    html_text = requests.get('https://www.timesjobs.com/candidate/job-search.html?searchType=personalizedSearch&from=submit&txtKeywords=python&txtLocation=').text

    # The format of the BeautifulSoup
    soup = BeautifulSoup(html_text, 'lxml')

    # Find all related job posts
    jobs = soup.find_all('li', class_ = 'clearfix job-bx wht-shd-bx')

    # Using a for loop to access all the information, index is used to maintain the position at which the data is relevant
    for index, job in enumerate(jobs):
        posted = job.find('span', class_ = 'sim-posted').span.text
        
        # Filtering out
        if 'few' in posted:
            
            # Strip method is used to remove the extra whitespaces
            companyName = job.find('h3', class_ = 'joblist-comp-name').text.strip()

            skill = job.find('span', class_ = 'srp-skills').text.strip()
    
            # Only the links will be printed when a['href' is used]
            more_info = job.header.h2.a['href']

            # Filtering out if not a relevant skill
            if notSkills not in skill:

                # Writing the data in separate txt files according to the different indices
                with open(f'posts/{index}.txt', 'w') as f:

                    # Printing out the relevant data
                    f.write(f"Company Name: {companyName}\n")
                    f.write(f"Required Skills: {skill}\n")
                    f.write(f"More Info: {more_info}\n")

                print(f'File saved: {index}')

# The main function which would run the program every 10 seconds and it will go on forever since an infinite while loop is used
if __name__ == '__main__':
    while True:
        findJobs()
        waitingTime = 10
        print(f'Waiting for {waitingTime} seconds')
        time.sleep(waitingTime)

import requests
from bs4 import BeautifulSoup
import time
def scrap():
    base_url = 'https://www.recommerce.com'
    try:
        response = requests.get(base_url)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"Error fetching {base_url}: {e}")
        return

    soup = BeautifulSoup(response.text, 'html.parser')
    link = soup.find('span', content='Tous les téléphones reconditionnés')

scrap()
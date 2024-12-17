import bs4 as bs
import requests
import pandas as pd

session = requests.Session()
HEADERS = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:133.0) Gecko/20100101 Firefox/133.0'}

products = []

def fetch_url(url):
    try:
        response = session.get(url, headers=HEADERS)
        response.raise_for_status()
        return bs.BeautifulSoup(response.text, "html.parser")
    except requests.exceptions.RequestException as e:
        print(f"Request failed: {e}")
        return None

def extract_product_info(product_url):
    soup = fetch_url(product_url)
    if not soup:
        return

    title = soup.find("span", {"data-ui-id": "page-title-wrapper"})
    price = soup.find("meta", property="product:price:amount")
    specs = soup.find("table", {"id": "product-attribute-specs-table"})

    product_info = {
        "Title": title.text if title else None,
        "Price": price['content'] if price else None
    }

    if specs:
        for row in specs.find_all("tr"):
            key = row.find("th")
            value = row.find("td")
            if key and value:
                product_info[key.text.strip()] = value.text.strip()

    products.append(product_info)

def scrap():
    soup = fetch_url("https://www.recommerce.com")
    if not soup:
        return

    element = soup.find("li", {"class": "level0 nav-2 category-item level-top renderer-default"})
    if not element:
        print("Element not found")
        return

    a_tag = element.find("a")
    if not a_tag or 'href' not in a_tag.attrs:
        print("`a` tag or `href` attribute not found")
        return

    soup2 = fetch_url(a_tag['href'])
    if not soup2:
        return

    product_links = [a['href'] for a in soup2.find_all("a", {"class": "product-item-link"}) if 'href' in a.attrs]
    print(f"Found {len(product_links)} products")
    print("Extracting product information")
    for product in product_links:
        extract_product_info(product)

    df = pd.DataFrame(products)
    print(df)
    df.to_csv("products.csv", index=False)
    print("Done")

scrap()
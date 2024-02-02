import os
import sys
import requests
from bs4 import BeautifulSoup
from markdownify import MarkdownConverter


class ProgrammersDescriptionGenerator:
    _module_path = os.path.dirname(os.path.abspath(__file__))

    def __init__(self, url, result_path, parser):
        self.url = url
        self.result_path = result_path
        self.parser = parser

    def request_html(self):
        res = requests.get(self.url)
        self.html = res.text

    def convert_html_bs4(self):
        self.soup = BeautifulSoup(self.html, self.parser)

    def parse(self):
        self.request_html()
        self.convert_html_bs4()

        category, title = self.find_category_title()
        categroy_path = os.path.join(self.result_path, category)
        title_path = os.path.join(categroy_path, title)

        self.make_dir(categroy_path)
        self.make_dir(title_path)
        self.write_markdown(os.path.join(title_path, "README.md"))

    def find_category_title(self):
        category_title_soup = self.soup.find("ol", "breadcrumb")
        _, category_soup, tilte_soup = category_title_soup.find_all("li")
        category = category_soup.get_text()
        title = tilte_soup.get_text()
        return category, title

    def make_dir(self, dir_name):
        if not os.path.exists(dir_name):
            os.mkdir(dir_name)

    def write_markdown(self, file_path):
        with open(file_path, "w", encoding="utf8") as f:
            description = self.soup.find("div", "guide-section-description")
            f.write(md(description))


def md(soup, **options):
    return MarkdownConverter(**options).convert_soup(soup)


if __name__ == "__main__":
    if len(sys.argv) != 1:
        url = sys.argv[1]
        result_path = sys.argv[2]

    pdg = ProgrammersDescriptionGenerator(url, result_path, "lxml")
    pdg.parse()
    print(f"Success. checking your result path:{result_path}")
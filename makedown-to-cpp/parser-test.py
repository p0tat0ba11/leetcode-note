import unittest
import os
from parser import extract_sections, parse_markdown, write_cpp_files

class TestParser(unittest.TestCase):
    def setUp(self):
        self.first_content = """int main() {\n    cout << \"Hello, World!\";\n    return 0;\n}\n"""
        self.second_content = """void foo() {}\n"""
        self.one_markdown = f"# Title\n\n```cpp=\n{self.first_content}```"
        self.two_markdown = f"# Title\n\n```cpp=\n{self.first_content}```\n\n```cpp=\n{self.second_content}```"
        self.one_cpp = [f"/*\n      Title\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\n{self.first_content}"]
        self.two_cpp = [f"/*\n      Title\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\n{self.first_content}",
                        f"/*\n      Title\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\n{self.second_content}"]
    
    def test_extract_sections(self):
        title, cpp_sections = extract_sections(self.two_markdown)
        self.assertEqual(title, "Title")
        self.assertEqual(len(cpp_sections), 2)
        self.assertIn(cpp_sections[0], self.first_content)
        self.assertIn(cpp_sections[1], self.second_content)

    def test_extract_sections_invalid(self):
        title, cpp_sections = extract_sections("Invalid content")
        self.assertIsNone(title)
        self.assertIsNone(cpp_sections)
        
    def test_write_cpp_files(self):
        write_cpp_files("Title", self.first_content, "test.cpp")
        self.assertTrue(os.path.exists("test.cpp"))
        with open("test.cpp", "r") as f:
            content = f.read()
        self.assertEqual(content, self.one_cpp[0])
        os.remove("test.cpp")
    
    def test_parse_markdown(self):
        with open("test.md", "w") as f:
            f.write(self.one_markdown)
        parse_markdown("test.md")
        self.assertTrue(os.path.exists("test.cpp"))
        with open("test.cpp", "r") as f:
            content = f.read()
        self.assertEqual(content, self.one_cpp[0])
        os.remove("test.cpp")

    def test_parse_markdown_multiple(self):
        with open("test.md", "w") as f:
            f.write(self.two_markdown)
        parse_markdown("test.md")
        self.assertTrue(os.path.exists("test"))
        for i, content in enumerate(self.two_cpp):
            with open(f"test/test-{i}.cpp", "r") as f:
                cpp_content = f.read()
            self.assertEqual(cpp_content, content)
            os.remove(f"test/test-{i}.cpp")
        os.rmdir("test")


    def test_parse_markdown_invalid(self):
        print()
        invalid_contents = ["# Title\n", f"""```cpp=\n{self.first_content}\n```"""]
        for content in invalid_contents:
            with open("test.md", "w") as f:
                f.write(content)
            parse_markdown("test.md")
            self.assertFalse(os.path.exists("Title.cpp"))
            os.remove("test.md")

if __name__ == "__main__":
    unittest.main()

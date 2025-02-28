import os
import re
import sys

def extract_sections(content):
    title = re.search(r'# (.+)', content)
    title = title.group(1) if title else None
    cpp_sections = re.findall(r'```cpp=\n(.+?)```', content, re.DOTALL)
    
    if(title != None and cpp_sections != None):
        return title, cpp_sections
    return None, None

def write_cpp_files(title, cpp_sections, output_path):
    with open(output_path, "w") as f:
        f.write(f"/*\n      {title}\n*/\n")
        f.write("#include<bits/stdc++.h>\nusing namespace std;\n\n")
        f.write(cpp_sections.strip() + "\n")

def parse_markdown(markdown):
    try:
        if os.path.isdir(markdown):
            for file in os.listdir(markdown):
                if file.endswith('.md'):
                    parse_markdown(os.path.join(markdown, file))
        else:
            with open(markdown, 'r') as f:
                content = f.read()
        
            title, cpp_sections = extract_sections(content)
            
            if not title or not cpp_sections:
                raise Exception(f"{markdown} does not follow the expected format.")
            
            basename = os.path.basename(markdown).split('.')[0]

            # if there are multiple sections, create a directory to store them
            if len(cpp_sections) > 1:
                os.makedirs(basename, exist_ok=True)
                for i, section in enumerate(cpp_sections):
                    write_cpp_files(title, section, f'{basename}/{basename}-{i}.cpp')
            else:
                write_cpp_files(title, cpp_sections[0], f'{basename}.cpp')
        os.remove(markdown)

    except Exception as e:
        print(f'Error: {e}')

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f'Usage: python {os.path.basename(__file__)} <markdown_file_or_directory>')
        sys.exit(1)
    else:
        parse_markdown(sys.argv[1])
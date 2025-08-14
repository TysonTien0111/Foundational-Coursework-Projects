html_string = input('Please enter a HTML string: ')

latex_string = html_string.replace('&ldquo;', '``')
latex_string = latex_string.replace('&rdquo;', '"')
latex_string = latex_string.replace('&apos;', "'")
latex_string = latex_string.replace('&amp;', '&')
latex_string = latex_string.replace('&lt;', '<')
latex_string = latex_string.replace('&gt;', '>')
latex_string = latex_string.replace('{', '\{')
latex_string = latex_string.replace('}', '\}')
latex_string = latex_string.replace('%', '\%')

print(f'{latex_string}')

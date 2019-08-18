**Assignments - Converting Images from Word to Markdown**

When converting Word docs to Markdown using Writetage, the images are inserted using `![]` notation. This needs to be converted to `<img ...` . Use the following regex, but note the width is always set to 400px

- **example**
  - `![Cool Image](media/file.png)`
  - `<img src="media/file.png" alt="Cool Image" style="width:400px" />`
- **find**
  `\!\[([a-zA-Z0-9.\/=_\-\?\& :]*)\]\(([a-zA-Z0-9.\/=_\-\?\&\\]*)\)`
- **replace**
  `<img src="$2" alt="$1" style="width:400px" />`
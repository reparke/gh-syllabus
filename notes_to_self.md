**Assignments - Converting Images from Word to Markdown**

When converting Word docs to Markdown using Writetage, the images are inserted using `![]` notation. This needs to be converted to `<img ...` . Use the following regex, but note the width is always set to 400px

- **example**
  - `![Cool Image](media/file.png)`
  - `<img src="media/file.png" alt="Cool Image" style="width:400px" />`
- **find**
  `\!\[([a-zA-Z0-9.\/=_\-\?\& :]*)\]\(([a-zA-Z0-9.\/=_\-\?\&\\]*)\)`
- **replace**
  `<img src="$2" alt="$1" style="width:400px" />`

  Theme
  https://jekyllthemes.io/theme/minimal-mistakes

  Installing theme
  https://mmistakes.github.io/minimal-mistakes/docs/quick-start-guide/#installing-the-theme

  Installing Jekyll for local testing
  https://docs.github.com/en/enterprise/2.14/user/articles/setting-up-your-github-pages-site-locally-with-jekyll

  Customization
  https://mmistakes.github.io/minimal-mistakes/docs/quick-start-guide/

  Liquid: Functions
  http://hamishwillee.github.io/2014/11/13/jekyll-includes-are-functions/

  Liquid: Date Formatting
  http://alanwsmith.com/jekyll-liquid-date-formatting-examples

  Liquid: Date Manipulation
  https://community.shopify.com/c/Shopify-Design/Simple-Date-Math-Manipulation-Help-Needed-for-Liquid/td-p/204393

  Liquid: Hack to Create Associate and Multi-Dimensional Arrays
  https://raisedbyturtles.org/shopify-associative-arrays
  Basically you can't. However you can create parallel arrays

  starting jekyll locally
  bundle exec jekyll serve
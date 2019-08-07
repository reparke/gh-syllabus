---
week: 1
day: September 1
title: First session
tags: [hello]
---
### Surname, Name: _Book title_

City: Publisher, 2017\. ISBN 123-45-678-9012-3.  
**Required excerpt: p. 55–90 (35 pages). [PDF]({{ site.docsUrl }}article.pdf)**

### Surname, Name: _Article title_  

In: Publication, Date. [Available online.](http://publication.com/article_url)  
**Entire article required (~5 pages). [PDF]({{ site.docsUrl }}cached-to-be-sure.pdf)**

## Recommended reading

### Surname, Name: _Article title_  

In: Publication, Date. [Available online.](http://publication.com/article_url)  

	<ul>
    {% for node in site.pages %}
      {% if node.url contains base_url %}
        {% assign node_url_parts = node.url | split: '/' %}
        {% assign node_url_parts_size = node_url_parts | size %}
        {% assign filename = node_url_parts | last %}
        {% if url_parts_size == node_url_parts_size and filename != 'index.html' %}
          <li><a href='{{node.url}}'>{{node.title}}</a></li>
        {% endif %}
      {% endif %}
    {% endfor %}
    </ul>
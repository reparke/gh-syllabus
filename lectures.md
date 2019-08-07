---
title: Lectures
layout: page
menuItem: Lectures
menuPosition: 2

---

{% if site.docsUrl != "" %}
You can download all required reading in the [Study materials]({{ site.docsUrl }}) at the faculty website.
{% endif %}

{% assign mydocs = site.lectures | group_by: 'week' %}
{% for cat in mydocs %}
<h2>Week - {{ cat.name }}</h2>
<ul>
    {% assign items = cat.items | sort: 'order' %}
    {% for item in items %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>
{% endfor %}

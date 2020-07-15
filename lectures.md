---
title: Lectures
category: lectures
layout: single
classes: wide

---



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

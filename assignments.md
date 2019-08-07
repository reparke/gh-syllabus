---
title: Assignments
layout: page
menuItem: Assignments
menuPosition: 3

---

{% if site.docsUrl != "" %}
You can download all required reading in the [Study materials]({{ site.docsUrl }}) at the faculty website.
{% endif %}

{% assign mydocs = site.assignments | group_by: 'week' %}
{% for cat in mydocs %}
<h2>Week - {{ cat.name }}</h2>
<ul>
    {% assign items = cat.items | sort: 'order' %}
    {% for item in items %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>
{% endfor %}

---

<ul>
{% assign syllabus = (site.assignments | sort: "number") %}
{% for week in syllabus %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	(Due: <b>{{ week.date_due }}</b>)</li>
{% endfor %}
</ul>




